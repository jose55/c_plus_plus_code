#ifndef BOMBSWEEPER_H
#define BOMBSWEEPER_H

#include <iostream>
#include <string>
#include "board.h"

using namespace std;

//////////////////////////////////////////
////         GLOBAL CONSTANTS         ////
//////////////////////////////////////////
////         use of these constants     //
////   will make you code more readable //
//////////////////////////////////////////



const char PLAY_RANDOM    = '1'; // These are the menu items for Main Menu.
const char PLAY_FROM_FILE = '2'; // Use these const variables in your main().
const char TOGGLE_COLOR   = '3'; // Use of '1'/'2' etc would result in substantial   
const char QUIT_MAIN_MENU = '4'; // reduction in style points.  

const char MARK  = 'M';			// menu items for Player Menu.
const char UNCOVER = 'U';
const char QUIT_PL_MENU = 'Q';



//REQUIRES: the conditions that must hold, if any
//MODIFIES: how inputs are modified, if any
//EFFECTS: what the procedure computes given legal inputs     



///////////////////////////////////////
//////FUNCTIONS YOU NEED TO WRITE//////
///////////////////////////////////////


/////////////////////////////////////////
//// BEFORE you begin writing these  ////
///  functions -- make sure you      ////
///  review and know and understand  ////
///  the functions that are written  //// 
///  for you                         ////
///  These pre-written functions     ////
///  are extremely helpful           ////
///  USE THEM                        ////
/////////////////////////////////////////


//EFFECTS: asks the user to input the total number of rows, 
//		   cols, and bombs that the board will have -- in this order. 
//		   I would highly suggest you use the getValue function for this
//
//		   loads the bombs using the function to create a randomized 
//         board(this function has been written for you). 
//		   plays the game.
//Note:    there is no need to error check inputs, this is done within
//			loadBombsRandomly if anything is out of range
//Prompts:
// "Enter the number of rows: "
// "Enter the number of cols: "
// "Enter the number of bombs: "
void playRandomGame();



//EFFECTS: asks user to enter the name of the file from which to 
//         load the bombs.
//         if file opens successfully, loads bombs from that file
//			otherwise, output appropriate error message and return
//		   if the load of bombs succeeded, plays the game
//			otherwise, output apropriate error message and return
//Note: as always, if there is an error from keyboard, get rid of all
//			data still on that line
//Prompts:
//cout << "Enter the filename: ";
//cout << SetColor(RED) << "Invalid load of bombs" << endl;
//cout << SetColor(RED) << "Unable to open file!" << endl;
void playFromFile();



//EFFECTS:  plays the game
//		prints the board and the player menu
//		    pay attention to if it is 'current board' or 'final board'
//		gets input from the user and performs
//        FYI: input is case-insensitive to allow the user to type 'M' or 'm' for mar, etc
//		on any error in input, it prints the appropriate error message, 
//		  and reprints the board and the player menu
//        you will also want to get rid of all that remains on that line
//        that contains the error in input
//		On either a win, loss, or 'Quit', you will want to uncover all the squares
//		   and print the board one last time
//		   and announce either the Win or Loss if appropriate
//	
//MODIFIES: board
//Prompts:
// cout << SetColor(GREEN) << "Current Board:" << endl;
// cout << SetColor(GREEN) << "Final Board:" << endl;
// cout << SetColor(GREEN) << "You win!" << endl;
// cout << SetColor(RED) << "You lose!" << endl;
//
//Error Messages:
// (not correct menu choice) 
//		cout << SetColor(RED) << "Invalid command" << endl;
// (row,col not ints)        
//		cout << SetColor(RED) << "Please enter two numbers" << endl;
// (row, col off board)      
//		cout << SetColor(RED) << "Your choice is out of bounds" << endl;
void playGame(Board & board);



///////////////////////////////////////
//////FUNCTIONS WRITTEN FOR YOU////////
///////////////////////////////////////

//EFFECTS: gets an integer value from the keyboard
//			checks to make sure it is an integer
//			if an int, returns the value
//			otherwise, clears the I/O state and dumps the line
//				and returns -1
//MODIFIES: nothing
int getValue (const string& prompt);



//EFFECTS:  prints the Main Menu.
//MODIFIES: cout
void printMainMenu();



//EFFECTS:  prints the Player Menu.
//MODIFIES: cout
void printPlayerMenu();

class effect
{


 public:

  effect(string);


};


#endif
