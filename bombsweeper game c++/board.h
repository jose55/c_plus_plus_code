#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>

using std::istream;

const int MAX_SIZE = 100;

struct Square
{
	bool isBomb;    //square is a bomb
	bool isShown;	//square has been uncovered
	bool isMarked;	//square has been marked as suspected bomb
	int number;	    //number of bombs adjacent to this tile
};

struct Board
{
	Square squares[MAX_SIZE][MAX_SIZE];
	int rows;			//total number of rows on this board
	int cols;			//total number of columns on this board
	int bombs;			//total number of bombs on this board
	int numSquaresTurned;	//number of squares that have been turned
};

//REQUIRES: the conditions that must hold, if any
//MODIFIES: how inputs are modified, if any
//EFFECTS:  what the procedure computes given legal inputs     

//////////////////////////////////////
//////FUNCTIONS WRITTEN FOR YOU///////
//////////////////////////////////////

//REQUIRES:	rows and cols to be within acceptable range
//MODIFIES: board
//EFFECTS:  will randomly place the bombs into the board
//CALLS:	initBoard, placeBomb
void loadBombsRandomly(Board & board, int bombs, int rows, int cols);



//EFFECTS:  prints the board
//MODIFIES: cout
void printBoard(const Board & board);



///////////////////////////////////////
//////FUNCTIONS YOU NEED TO WRITE//////
///////////////////////////////////////

//EFFECTS: Checks to make sure that row and col lie within
//		   the boundary of the board. Returns true if on the board, 
//		   false otherwise.
//         (this check is required to ensure that we do not do
//		   something foolish with the memory that isn't ours)
bool validPlace(const Board & board, int row, int col);



//MODIFIES: Board board
//EFFECTS:  Initializes the board for the number of rows and cols passed in
//          Make sure you initialize ALL parts of board.
//          board.rows should be initialized to rows
//          board.cols should be initialized to cols
//          All others should be initialized to either 0 or false
//          whichever is appropriate for the datatype
void initBoard(Board & board, int rows, int cols);



//REQUIRES: row, col must be on the board
//EFFECTS:  returns true if the square at this location is 
//			marked, false otherwise
bool isMarked(const Board &board, int row, int col);



//REQUIRES: row, col must be on the board
//EFFECTS:  returns true if the square at this location has been uncovered,
//	        false otherwise
bool isShown(const Board &board, int row, int col);



//REQUIRES: row,col must be on the board
//EFFECTS:  returns true if the square at row,col is a bomb
bool isBomb(const Board & board, int row, int col);



//REQUIRES: row, col to be on the board
//MODIFIES: board
//EFFECTS:  Toggles whether a square is marked. 
//          If square is marked, unmark it,
//          otherwise mark it.
//Note:     a square that is already shown should not be marked
void toggleMark(Board & board, int row, int col);



//MODIFIES: board
//EFFECTS:  increments the 'number' at this location because 
//          a bomb has been added to an adjacent location.
//          unless there is a bomb at this location -- then don't increment
//NOTE:     this does NOT require row, col are on the board
//          Therefore, if row,col is not within bounds of the array, 
//                     do nothing (just return)
void incCount(Board & board, int row, int col);



//REQUIRES: row,col must be on the board
//MODIFIES: board, board.bombs
//EFFECTS:  Places a bomb on the board at this location
//          sets the count on this square equal to 0
//          and readjusts the counts on squares adjacent
//          to this one (adjacent squares are the 8 squares
//          surrounding the one at [row][col].  
//			Hint    : CALLS incCount
//			adjusts the number of bombs
void placeBomb(Board & board, int row, int col);



//MODIFIES: board
//EFFECTS:  Uncovers a square and if 'blank' (no bomb, no number indicating 
//			adjacent bombs) uncovers all adjacent squares (all 8 surrounding
//			squares).
//          returns true if a bomb is located at this square,
//          false otherwise.
//			NOTE: this does NOT require row, col to be on the board
//			these checks are done within the function and used to
//			your advantage
//Specifically: if row, col are not valid (within array) return false
//			if it's marked, return false
//			if it's a bomb, return true
//			if it's shown (uncovered) already, return false
//			now that it's passed all the checks, set this square as shown
//			if the square we turned over is blank (see above for definition),
//			we need to turn over all the adjacent squares (check all 8 surrounding it)
//			  uncover them if needed
//			update numSquaresTurned
bool uncoverSquare(Board & board, int row, int col);



//EFFECTS:  will mark all places on the board as shown. Make sure  
//          to update ALL relevent parts of board.
//			Also very useful for testing and debugging this program.
//MODIFIES: Board board
//Hint:     you don't have to use uncoverSquare
void uncoverAll(Board & board);



//MODIFIES: board, in
//EFFECTS:  Loads bombs from a file into a board.
//		    Follows the format of the file as described in the spec 
//	* NOTE:
//	* since this is an all-or-none process we can just
//	* pretend all is well until the end when we should actually check
//	* (iow, we're not going to check the state of the stream until the end)
//		    
//			Initialize the board
//			The first 2 lines of the file give the number of bombs, 
//		    and the number of rows&columns. 
//			Make sure the number of rows and columns are within range, if not return
//            (within range: between (0, MAX_SIZE]
//			make sure the number of bombs is within range, if not return
//            (within range: between [0, number of squares]
//			Read in the locations of the bombs and place them into the board
//			make sure they are within range. Error checks to make 
//			sure that the number of bombs matches the indicated 
//			number of bombs.
//			update all appropriate info with board
//		    returns true if the file is read correctly,
//		    false otherwise
//Hint:     CALLS  initBoard, placeBomb
//The istream in this function is correct, this means you could
//pass cin to this function and type out what a file would look like
bool loadBombsFromFile(Board & board, istream & in);


//EFFECTS:  Checks the board for a win.
//		    returns true if there is a win,
//			false otherwise
// A win occurs when all non-bomb squares have been shown
bool isWin(const Board & board);


#endif
