
#include <iostream>
#include "helperFunctions.h"
#include <cmath>

//______________________________NEEDS TO BE TESTED___________________should work
//REQUIRES:  
//MODIFIES:
//EFFECTS: rounds val and returns
//         .5 rounds up
int roundToInt(double val)
{
    int rounded;
    return rounded = (val + 0.5);
}

//______________________________NEEDS TO BE TESTED___________________should work
// Requires:  value to represent red, green, or blue
// Effects: corrects a color value to be within 0 - 255 inclusive
//		 if value is outside this range, adjusts to either 0 or 255
//		 whichever is closer
int correctValue(int value)
{
    if (value<0)
    {
        return 0;
    }
    if (value>255)
    {
        return 255;
    }
    return value;
}
