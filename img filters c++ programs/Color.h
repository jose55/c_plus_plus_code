#ifndef __COLOR_HEADER_FILE__
#define __COLOR_HEADER_FILE__

class Color
{	
public:
	// default constructor
	// Effects: default value is WHITE
	Color();

	//constructor taking RGB values
	//Modifies: red, green, blue
	//Effects:  assigns values into corresponding data members
	//          makes sure values are 0-255
	//          if outside, assigns 0 or 255 whichever is closest
	Color(int redVal, int greenVal, int blueVal);


	//constructor taking an int value that represents the color
	//Modifies: red, green, blue
	//Effects:  takes the 'int' and pulls out the RGB values
	//          assigns values into corresponding data members
	Color (int colorVal);


	//Effects: returns the amount of red at this pixel
	//		   value ranges from 0-255; 0 is no red; 255 is max red
	int getRed() const; 


	//Effects: returns the amount of green at this pixel
	//  value ranges from 0-255; 0 is no green; 255 is max green
	int getGreen() const;


	//Effects: returns the amount of blue at this pixel
	//	  value ranges from 0-255; 0 is no blue; 255 is max blue
	int getBlue() const; 


	//Modifies: red
	//Effects: sets 'red' to the new red value
	//         makes sure value is 0-255
	//         if outside, assigns 0 or 255 whichever is closest
	void setRed(int value);


	//Modifies: green
	//Effects: sets 'green' to the new green value
	//         makes sure value is 0-255
	//         if outside, assigns 0 or 255 whichever is closest
	void setGreen(int value);


	//Modifies: blue
	//Effects: sets 'blue' to the new blue value
	//         makes sure value is 0-255
	//         if outside, assigns 0 or 255 whichever is closest
	void setBlue(int value);


	//Effects: takes the red, green, blue values; converts it to the corresponding int
	//         and returns this int
	int RGB_to_int() const;


	//Requires: testColor to be a valid Color
	//Effects: returns the "distance" between the current Pixel's color and  
	//		   the passed color
	//		   uses the same formula as finding distance on a
	//		   Cartesian coordinate system in 3-dimensional space
	//         i.e.,distance between Point (x1, y1, z1) and Point(x1, y2, z2) 
	//         only with Color(color1) and Color(color2) with red, green, blue
	double colorDistance(const Color & testColor) const;



	//Effects: returns the average of the red, green, and blue values of this pixel
	//         rounds to the closest int
	//         on a .5 decimal, it will round up
	int getAverage() const;


	//Effects: turns the current pixel to a gray
	//         will use average
	//Note: all true grays have red == green == blue
	void grayScale();


	//Modifies:  red
	//Effects: changes red by the percentage passed in
	//		if (0.7) is passed in, it will decrease red
	//		by 30% (i.e., 70% of original amount)
	//		if you want to eliminate red, pass in (0.0)
	//	    make sure that red is 0 - 255
	//	    when converting from double to int - always round
	void scaleRed(double scaleVal); 


	//Modifies:  green
	//Effects: changes green by the percentage passed in
	//		if (0.7) is passed in, it will decrease green
	//		by 30% (i.e., 70% of original amount)
	//		if you want to eliminate green, pass in (0.0)
	//      make sure that green is 0 - 255
	//    when converting from double to int - always round
	void scaleGreen(double scaleVal); 


	//Modifies:  blue
	//Effects: changes blue by the percentage passed in
	//		if (0.7) is passed in, it will decrease blue
	//		by 30% (i.e., 70% of original amount)
	//		if you want to eliminate blue, pass in (0.0)
	//      make sure that blue is 0 - 255
	//    when converting from double to int - always round
	void scaleBlue(double scaleVal); 


	//Effects: takes the current color and applies 
	//         scaleRedVal to red of color
	//         scaleGreenVal to green of color and
	//         scaleBlueVal to blue of color
	//         when converting from double to int - always round
	void scaleColor(double scaleRedVal, double scaleGreenVal, double scaleBlueVal);


	//Effects: outputs to the default output device 
	//         the red, green, and blue componenents
	//         separated by a space
	void printColor();


	//Requires: right is a valid Color
	//Effects: returns true if the two colors are exactly equal
	//         i.e., reds, greens, and blues are equal
	//         false otherwise
	bool operator == (const Color right) const;


	//Requires:  right is a valid Color
	//Effects:  returns the difference of the two Colors
	//          will take the absolute value of the difference of 
	//          the RGB's to form the Color returned 
	Color operator - (const Color right) const;


	//Requires:  value to be between 0-255
	//Effects:  returns true if red,green, and blue are all less than
	//          or equal to value
	//          otherwise, returns false
	bool operator <= (int value) const;




private:
	int red, green, blue;

};


const Color BLACK = Color(0, 0, 0);
const Color WHITE = Color(255, 255, 255);

const Color GREY = Color(84, 84, 84);
const Color SILVER_GREY = Color(192, 192, 192);
const Color SLATE_GREY = Color(112, 128, 144);
const Color DARKGREY = Color(169, 169, 169);

const Color UM_BLUE = Color(0, 0, 51);
const Color BLUE_VIOLET = Color(138, 42, 226);
const Color LIGHT_BLUE = Color(173,216,230);
const Color MEDIUM_BLUE = Color(0, 0, 205);
const Color ROYAL_BLUE = Color(67, 110, 238);
const Color SKY_BLUE = Color(135, 206, 235);
const Color AQUAMARINE = Color(127, 255, 212);
const Color BLUE = Color(0, 0, 255);
const Color CYAN = Color(0, 255, 255);
const Color NAVY = Color(0, 0, 128);

const Color BEIGE = Color(245, 245, 220);
const Color BROWN = Color(166,42,42);
const Color CHOCOLATE = Color(139, 69, 19);

const Color GREEN = Color(0, 255, 0);
const Color FOREST_GREEN = Color(34, 139, 34);
const Color LIME_GREEN = Color(50, 20, 50);
const Color SPRING_GREEN = Color(0, 255,  127);
const Color CHARTREUSE = Color(127, 255, 0);
const Color KHAKI = Color(240, 230, 140);

const Color DARK_ORANGE = Color(255, 140, 0);
const Color ORANGE = Color(155, 165, 0);
const Color DEEP_PINK = Color(255, 20, 147);
const Color HOT_PINK = Color(255, 105, 180);
const Color PINK = Color(255, 192, 203);
const Color RED = Color(255, 0, 0);
const Color DARK_ORCHID = Color(153, 50, 204);
const Color MEDIUM_ORCHID = Color(186, 85, 211);
const Color MAGENTA = Color(255, 0, 255);
const Color ORCHID = Color(218, 112, 214);
const Color PURPLE = Color(128, 0, 128);
const Color DARK_PURPLE = Color(135, 31, 120);

const Color MAIZE = Color(255, 204, 51);
const Color GOLDENROD = Color(218, 193, 37);
const Color LIGHT_YELLOW = Color(255, 255, 224);
const Color YELLOW = Color(255, 255, 0);
const Color GOLD = Color(255, 215, 0);

#endif
