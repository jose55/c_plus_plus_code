// Fredrik Kjellberg, fredrikj  
// Mathias Arkayin, markayin

#include "bombsweeper.h"
#include "ioutil.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

int main()
{
    char menuchoice;
    
    do {
        printMainMenu(); // prints main menu
        cin >> menuchoice; // takes the user iput and saves it in menuchoice
        switch (menuchoice) 
        {
            case PLAY_RANDOM:  // true if play random game 
                playRandomGame();
                break;
                
            case PLAY_FROM_FILE: // true if play game from file 
                playFromFile();
                break;
                
            case TOGGLE_COLOR: // true if turning color on or off
                SetColor::toggleColor(); 
                break;
                
            case QUIT_MAIN_MENU: // true if you want to end game
                cout << "Thank you for playing!" << endl;
                break;
                
            default:
                cin.clear();// -----------CLEAR DATA------------
                cin.ignore(INT_MAX, '\n');// -----------DUMP DATA------------
                cout << SetColor(RED) << "Invalid menu choice" << endl;
                break;
        }
        
    } while (menuchoice != QUIT_MAIN_MENU); // will keep asking the user if he/she wants to play a new game untill they quit the program from the main menu! then this will becom false and the program ends.
	return 0;
}

//********************************************************************
void playRandomGame()
{
    Board board;
    
    int rows = getValue("Enter the number of rows: "); // prompts the player for the number of rows
    
    int cols = getValue("Enter the number of cols: "); // prompts the player for the number of columns
    
    int bombs = getValue("Enter the number of bombs: "); // prompts the player for the number of bombs
    
    loadBombsRandomly(board, bombs, rows, cols);
    
    playGame(board); // play game
    
}
//*******************************************************************
void playFromFile()
{
    Board boardfile;
    
    string FileName;
    cout << "Enter the filename: "; //prompts the player for the file name
    cin >> FileName;// reads in filename
    fstream bombFile;
    bombFile.open(FileName.c_str()); // converts filename to c string
    
    if (!bombFile) // if the file does not open or there is no file 
    {
        cout << SetColor(RED) << "Unable to open file!" << endl;
        return;
    }
    else if (loadBombsFromFile(boardfile, bombFile) == false) // if Invalid load of bombs
    {
        cout << SetColor(RED) << "Invalid load of bombs" << endl;
        return;
    }
    playGame(boardfile); // play game - if it passes the other condictions
}
//**********************************************************************
void playGame(Board & board)
{
    char playerMenuChoice;
    int playerRow, playerCol;
    
    while (playerMenuChoice != QUIT_PL_MENU)
    {   
        cout << SetColor(GREEN) << "Current board:" << endl; // prints board
        printBoard(board);
        
        printPlayerMenu(); //prints player menu
        
        cin >> playerMenuChoice; // player enters menu choice and coordinates
        playerMenuChoice = toupper(playerMenuChoice); // converts the menuchoice char to an upper case letter if lower case
        
        switch (playerMenuChoice) // switch statment containing all choices, MARK , UNCOVER and QUIT
        {
            case MARK: 
                cin >> playerRow >> playerCol; // takes the user input of colum and row
                if (!(cin.good())) // ERROR: if the move is not digits
                {
                    cin.clear();// -----------CLEAR DATA------------
                    cin.ignore(INT_MAX, '\n');// -----------DUMP DATA------------
                    cout << SetColor(RED) << "Please enter two numbers" << endl;
                }
                else if (validPlace(board, playerRow, playerCol) == false) // ERROR: if the move is out of bounds
                {
                    cin.clear();// -----------CLEAR DATA------------
                    cin.ignore(INT_MAX, '\n');// -----------DUMP DATA------------
                    cout << SetColor(RED) << "Your choice is out of bounds" << endl;
                }
                else // if the move is VALID
                {
                    toggleMark(board, playerRow, playerCol); // MARKS or UN-MARKS THE SQUARE
                }
                break;
                
            case UNCOVER:
                cin >> playerRow >> playerCol; // takes the user input of colum and row
                if (!(cin.good())) // ERROR: if the move is not digits
                {
                     cin.clear();// -----------CLEAR DATA------------
                     cin.ignore(INT_MAX, '\n');// -----------DUMP DATA------------
                    cout << SetColor(RED) << "Please enter two numbers" << endl;
                }
                else if  (validPlace(board, playerRow, playerCol) == false) // ERROR: if the move is out of bounds
                {
                    cin.clear();// -----------CLEAR DATA------------
                    cin.ignore(INT_MAX, '\n');// -----------DUMP DATA------------
                    cout << SetColor(RED) << "Your choice is out of bounds" << endl;
                }
                else // if the move is VALID
                {
                    if (uncoverSquare(board, playerRow, playerCol) == true) // the player just uncovered a bomb so you loose 
                    {
                        uncoverAll(board);
                        cout << SetColor(GREEN) << "Final Board:" << endl;
                        printBoard(board); // prints final board with all sqauares uncovered 
                        cout << SetColor(RED) << "You lose!" << endl;
                        return; // exits the playgame functions and goes back to the main menu
                    }
                    if (isWin(board) == true) //player just uncovered all tiles that needs to be uncovered for a win
                    {
                        uncoverAll(board);
                        cout << SetColor(GREEN) << "Final Board:" << endl;
                        printBoard(board); // prints final board with all sqauares uncovered 
                        cout << SetColor(GREEN) << "You win!" << endl;
                        return; // exits the playgame functions and goes back to the main menu
                    }
                }
                break;
                
            case QUIT_PL_MENU: // when the user wants to quit
                cout << SetColor(GREEN) << "Final Board:" << endl;
                uncoverAll(board); // uncovers all the squares
                printBoard(board); // prints the board
                break;
                
            default: // if the user did not enter any valid menu choice 
                cin.clear();// -----------CLEAR DATA------------
                cin.ignore(INT_MAX, '\n');// -----------DUMP DATA------------
                cout << SetColor(RED) << "Invalid command" << endl;
                break;
        }
    }
}             

//**********************************************************************

//**********************************************************************
//               FUNCTIONS BELOW HAVE BEEN WRITTEN FOR YOU
//**********************************************************************

//**********************************************************************

int getValue(const string & prompt)
{
	int val;
	
	if (cout << prompt, !(cin >> val))
	{
		cin.clear();
		string junk;
		getline(cin, junk);
		return -1;
	}
	return val;
}

//***********************************************************************

void printMainMenu()
{
	cout << endl;
	cout << "Bombsweeper Main Menu" << endl;
	cout << "  1    Start randomized game" << endl;
	cout << "  2    Start game from file" << endl;
	cout << "  3    Toggle color on/off" << endl;
	cout << "  4    Quit" << endl;
}
//************************************************************************

void printPlayerMenu()
{
	cout << endl;
	cout << "Select a command" << endl;
	cout << "  M <row> <col>     Mark (or unmark) a bomb" << endl;
	cout << "  U <row> <col>     Uncover a square" << endl;
	cout << "  Q                 Quit current game, return to main menu" << endl << endl;
}
//************************************************************************
