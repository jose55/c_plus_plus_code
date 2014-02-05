#include "ioutil.h"

using std::ostream;
using std::cout;
using std::endl;

const int NUM_COLORS = 15;
const int NUM_LAYERS = 2;

bool SetColor::colorOn = true;

bool SetColor::toggleColor()
{
	colorOn = !colorOn;
	return colorOn;
}

#if defined _WIN32

#include <windows.h>

#else

//Declare the constants required to use the array
#define BACKGROUND_RED		1
#define BACKGROUND_GREEN	2
#define BACKGROUND_BLUE		4
#define FOREGROUND_RED		1
#define FOREGROUND_GREEN	2
#define FOREGROUND_BLUE		4
#define FOREGROUND_INTENSITY	0
#define BACKGROUND_INTENSITY	0

#endif

//Array to map a color, layer pair to a windows-defined constant
int colors[NUM_LAYERS][NUM_COLORS] = {{0, BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_GREEN, BACKGROUND_RED, BACKGROUND_BLUE | BACKGROUND_RED, BACKGROUND_GREEN | BACKGROUND_RED, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED,
                                        BACKGROUND_BLUE | BACKGROUND_INTENSITY, BACKGROUND_GREEN | BACKGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY, BACKGROUND_RED | BACKGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY},
                                       {0, FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_BLUE | FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_BLUE | FOREGROUND_RED, FOREGROUND_GREEN | FOREGROUND_RED, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,
									    FOREGROUND_BLUE | FOREGROUND_INTENSITY, FOREGROUND_GREEN | FOREGROUND_INTENSITY, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY, FOREGROUND_RED | FOREGROUND_INTENSITY, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY}};


#if defined WIN32

/************
 * SetColor *
 ************/

//Operator called when setting a color
SetColor operator << (ostream & out, const SetColor & c)
{
	if(!SetColor::colorOn)
	{
		c.out = &out;
		return c;
	}

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hConsole, &info);
	WORD oldVal = info.wAttributes;

	WORD oldForeVal = oldVal & (FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	WORD oldBackVal = oldVal & (BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);

	WORD newForeVal = c.layer == FORE ? colors[c.layer][c.color] : oldForeVal;
	WORD newBackVal = c.layer == BACK ? colors[c.layer][c.color] : oldBackVal;
	
	WORD oldSingleVal = c.layer == FORE ? oldForeVal : oldBackVal;
	Color oldColor = GRAY;

	//Find the color enum val corresponding to the old value
	for(int i = BLACK; i <= WHITE; i ++)
	{
		if(colors[c.layer][i] == oldSingleVal)
		{
			oldColor = static_cast<Color>(i);
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, newForeVal | newBackVal);

	return SetColor(oldColor, c.layer, out);
}

void SetColor::restore()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hConsole, &info);
	WORD oldVal = info.wAttributes;

	WORD oldForeVal = oldVal & (FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	WORD oldBackVal = oldVal & (BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);

	WORD newForeVal = layer == FORE ? colors[layer][color] : oldForeVal;
	WORD newBackVal = layer == BACK ? colors[layer][color] : oldBackVal;
	
	WORD oldSingleVal = layer == FORE ? oldForeVal : oldBackVal;
	Color oldColor = GRAY;

	//Find the color enum val corresponding to the old value
	for(int i = BLACK; i <= WHITE; i ++)
	{
		if(colors[layer][i] == oldSingleVal)
		{
			oldColor = static_cast<Color>(i);
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, newForeVal | newBackVal);
}

/***************
 * ClearScreen *
 ***************/

ostream & ClearScreen(ostream & out)
{
	system("cls");
	return out;
}

#else

#include <cstdio>

/************
 * SetColor *
 ************/

SetColor operator << (ostream & out, const SetColor & c)
{
	if(!SetColor::colorOn)
	{
		c.out = &out;
		return c;
	}

	int color = colors[c.layer][c.color];
	color += (c.layer == BACK) ? 40 : 30;

	char command[13];

	if(c.color > GRAY && c.layer == FORE)
	{
		sprintf(command, "%c[%d;%dm", 0x1B, 1, color);
	}
	else
	{
		sprintf(command, "%c[%dm", 0x1B, color);
	}

	out << command;

	c.out = &out;
	return c;
}

void SetColor::restore()
{
	char command[13];
	sprintf(command, "%c[0m", 0x1B);
	*out << command;
}


/***************
 * ClearScreen *
 ***************/

ostream & ClearScreen(ostream & out)
{
	system("clear");
	return out;
}

#endif
