// Fredrik Kjellberg, fredrikj  
// Mathias Arkayin, markayin

#include "board.h"
#include "ioutil.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <ctype.h>

using namespace std;

///////////////////////////////////////
//////FUNCTIONS WRITTEN FOR YOU////////
///////////////////////////////////////


//Creates a randomized board
void loadBombsRandomly(Board & board, int bombs, int rows, int cols)
{
	//Make sure parameters are ok
    if(!(rows > 0 && rows <= MAX_SIZE && cols > 0 && cols <= MAX_SIZE)){
        cout << "Your rows and/or cols are invalid, setting both to 10.\n\n";
        rows = cols = 10;
    }
    
	initBoard(board, rows, cols);
    
	//allocate the board
	board.rows = rows;
	board.cols = cols;
    
	//seed the random number generator
	srand(static_cast<unsigned int>(time(NULL)));
    
	//lower the number of bombs if it's greater than the number of squares
    
	if(bombs > rows * cols) 
	{
        cout << "Invalid number of bombs, setting them to " << rows*cols 
        << endl << endl;
		bombs = rows * cols;
	}
    
	//randomly place all the bombs
	for(int i = 0; i < bombs; i++)
	{
		int bombSpace = rand() % (rows * cols);
        
		while(board.squares[bombSpace / cols][bombSpace % cols].isBomb)
		{
			bombSpace++;
			bombSpace %= (rows * cols);
		}
        
		//find the row and column of the new bomb
		int row = bombSpace / cols;
		int col = bombSpace % cols;
        
		placeBomb(board, row, col);
	}
}

//*****************************************************************************


//prints the Board
void printBoard(const Board & board)
{
	//print the number of bombs marked
	cout << endl;
    
	//prints the top row of numbers
	cout << "    ";
	for(int i = 0; i < board.cols; i++)
	{
		cout << ' ' << i;
	}
	cout << endl;
    
    
	//print top line
	cout << "   +";
	for(int i = 0; i < board.cols; i++) 
	{
		cout << "--";
	}
	cout << '-';
	cout << "+" << endl;
    
	//print the rest of the board
	static Color colors[] = {BLACK, DARK_CYAN, DARK_MAGENTA, DARK_BLUE, DARK_GREEN, BLUE, GREEN, YELLOW};
    
	for(int row = 0; row < board.rows; row++)
	{
		printf("%2d", row);
		cout << " |";
        
		for(int col = 0; col < board.cols; col++)
		{
			Square square = board.squares[row][col];
            
			if (isShown(board,row,col) && isMarked(board, row, col) && isBomb(board, row, col))
			{
				cout << SetColor(DARK_RED, BACK) << " B";
			}
			else if(isShown(board,row,col) && isBomb(board, row, col))
			{
				cout << SetColor(RED, BACK) << " B";
			}
			else if(isMarked(board, row, col))
			{
				cout  << SetColor(DARK_YELLOW, BACK) <<  " M";
			}
			else if(isShown(board,row,col) && square.number == 0)
			{
				cout  << SetColor(WHITE, BACK) << "  ";
			}
			else if(isShown(board,row,col))
			{
				cout << " " << SetColor(colors[square.number], BACK) << square.number;
			}
			else
			{
				cout << " ?";
			}
		}
        
		cout << " |" << endl;
	}
    
	//print bottom line
	cout << "   +";
	for(int i = 0; i < board.cols; i++) 
	{
		cout << "--";
	}
	cout << '-';
	cout << "+" << endl;
	cout << endl;
}

///////////////////////////////////////
//////FUNCTIONS YOU NEED TO WRITE//////
///////////////////////////////////////

//*****************************************************************************
bool validPlace(const Board & board, int row, int col)
{
    if (row >= 0 && row < board.rows && col >= 0 && col < board.cols) // true if row and col are within the board
    {
        return true;
    }
    else
    {    
        return false;
    }   
}
//*****************************************************************************
void initBoard(Board & board, int rows, int cols)
{
    board.rows = rows; // sets rows and cols
    board.cols = cols;
    board.bombs = 0; // sets bombs to zero
    board.numSquaresTurned = 0; // sets number of turned to zero
    
    for (int i = 0; i < rows; i++)
    {    
        for (int j = 0; j < cols; j++) // loops trought and sets all to zero
        {
            board.squares[i][j].isBomb = 0;
            board.squares[i][j].isShown = 0;
            board.squares[i][j].isMarked = 0;
            board.squares[i][j].number = 0;
        }
    }
}
//*****************************************************************************
bool isMarked(const Board & board, int row, int col)
{
    return board.squares[row][col].isMarked; // returns true if the square at this location is marked
}

//*****************************************************************************
bool isShown(const Board & board, int row, int col)
{
	return board.squares[row][col].isShown; //returns true if the square at this location has been uncovered
}

//*****************************************************************************
bool isBomb(const Board & board, int row, int col)
{
	return board.squares[row][col].isBomb; //returns true if the square at row,col is a bomb
}

//*****************************************************************************
void toggleMark(Board & board, int row, int col)
{
    if (board.squares[row][col].isShown != true)// a square that is already shown should not be marked
    {
        if (board.squares[row][col].isMarked == true)
        {
            board.squares[row][col].isMarked = false; // If square is marked, unmark it
        }
        else
        {
            board.squares[row][col].isMarked = true; //  otherwise mark it
        }    
    }
}

//*****************************************************************************
void incCount(Board & board, int row, int col)
{
    if (validPlace(board, row, col) == true && isBomb(board, row, col) == false)//make sure within bounds of array
    {
        board.squares[row][col].number++; //increments the 'number' at this location because a bomb has been added to an adjacent location.
        return;
    }
    return;    
}
//*****************************************************************************
void placeBomb(Board & board, int row, int col)
{
    if (board.squares[row][col].isBomb == false) // Makes sure that we dont place a bomb in the same place as we already have a bomb
    {
        board.squares[row][col].isBomb = true; //mark as bomb
        
        board.squares[row][col].number = 0;
        
        //increment count on tiles adjacent
        incCount(board, row-1, col-1); // upper left
        incCount(board, row-1, col); // upper middle 
        incCount(board, row-1, col+1); // upper right
        incCount(board, row, col+1); // right
        incCount(board, row+1, col+1); // lower right
        incCount(board, row+1, col); // lower middle
        incCount(board, row+1, col-1); // lower left    
        incCount(board, row, col-1); // left
        //increment board.bombs
        board.bombs++;
    }  
}
//*****************************************************************************
bool uncoverSquare(Board & board, int row, int col)
{
	//check that row and col are valid - need to be within array
	// if not, return false
    if (validPlace( board, row, col) == false)
    {
        return false; //if it's not valide place
    }
    if (isMarked(board, row, col) == true)
    {
        return false;  //if it's marked, return false
    }
    if (isBomb(board, row, col) == true)
    {
        return true;  //if it's a bomb, return true
    }
    if (isShown(board, row, col) == true)
    {
        return false; //if it's shown already, return false
    }
    // if it passed all these we will set the square to be shown as it means that there is no bomb, not out of bound, and it is not already marked
    board.squares[row][col].isShown = true; //passed the checks, set this tile as shown
    board.numSquaresTurned++;
    if (board.squares[row][col].number == 0)
    {
        for(int i = row-1; i <= row+1 ;i++)
        {
            for (int j = col-1; j <= col+1 ;j++)
            {
                uncoverSquare(board , i, j); //loops around and uncovers adjecents by using the same function
            }
        }
    }
return false;
}


//*****************************************************************************
void uncoverAll(Board & board)
{
    for (int i = 0; i < board.rows; i++) // loops trough the board
    {
        for (int j = 0; j < board.cols; j++)
        {
            if (board.squares[i][j].isShown == false) // uncovers all sqares that are not already uncovered both bombs and non-bombs
            {
                board.squares[i][j].isShown = true;
                board.numSquaresTurned++; // increments numSquaresTurned
            }
        }
    }
}


//*****************************************************************************
bool loadBombsFromFile(Board & board, istream & in)
{
	int numberOfBombs;
	in >> numberOfBombs; // get the number of bombs
    if (numberOfBombs >= 0) // makes sure that bombs are not negative
    {    
        int filerows, filecols;
        in >> filerows >> filecols; // get the number of rows and number of columns
        
        if (filerows > 0 && filerows <= MAX_SIZE && filecols > 0 && filecols <= MAX_SIZE) //Make sure rows and columns are valid
        {
            if (numberOfBombs > filerows * filecols) //Make sure that the number of bombs are valid (not larger than board)
            {
                return false; // returns false if number of bombs are negative or larger than the number of squares on the board
            }
            
            initBoard(board, filerows, filecols); // initializes board
            
            int rowCoordinate, colCoordinate; 
            
            for (int count = 0; count < numberOfBombs;count++)// checks that the file is good and that the the bomb coordinates are on the board.
            {
                in >> rowCoordinate >> colCoordinate; // read in location of subsequent bombs
                if (validPlace(board, rowCoordinate, colCoordinate) ==  true)
                {   
                    placeBomb(board, rowCoordinate, colCoordinate); // places bomb on the board
                }
            }
            if (!(in.fail()) && numberOfBombs == board.bombs) // checks that the number of bombs matches the indicated number of bombs
            {
                return true;
            }
        }
    }
    return false; // returns false if something went wrong - this is done so that we know when to print that there was somthing wrong with the file that we tried to read
}

//*****************************************************************************
bool isWin(const Board & board)
{
    if (board.numSquaresTurned == (board.rows*board.cols) - board.bombs) // if the number of squares turned is the same as total number of squares minus bombs return true
    {
        return true; // winner winner chicken dinner!!!!!!!
    }
    return false;
}