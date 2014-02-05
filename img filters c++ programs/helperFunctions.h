#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

//REQUIRES:  
//MODIFIES:
//EFFECTS: rounds val and returns
//         .5 rounds up
int roundToInt (double val);


// Requires:  value to represent red, green, or blue
// Effects: corrects a color value to be within 0 - 255 inclusive
//		 if value is outside this range, adjusts to either 0 or 255
//		 whichever is closer
int correctValue(int value);

#endif

