#ifndef __IMAGE_HEADER_FILE__
#define __IMAGE_HEADER_FILE__

#include <string>

#include "Color.h"

//a definition of the acceptable colorModes
#define GRAY_8BPP				1
#define HIGH_COLOR_16BPP		2
#define TRUE_COLOR_24BPP		3

// needed for the loadBMP and saveBMP
struct bmp_info_header{
	unsigned int	info_size; 
	unsigned int	width; 
	unsigned int	height; 
	short	plane; 
	short	bpp; 
	int	compression; 
	unsigned int	image_size; 
	int	ppm_x; 
	int	ppm_y;
	int	colors; 
	int	important_colors; 
	bmp_info_header();
}; 

#define BMP_INFO_SIZE	sizeof(bmp_info_header)

class Image{
public:

	//default constructor
	//NOTE: there are 4 private data members
	//      width, height, colorMode, and pixelData -- all 4 get set as listed below
	//Modifies: colorMode to GRAY_8BPP; width, height, and pixelData to 0
	Image();



	//Requires: size_x >= 0; size_y >= 0; 
	//NOTE: there are 4 private datamembers
	//      width, height, colorMode and pixelData -- all 4 get set as listed below
	//Modifies: width, height, colorMode to corresponding arguments
	//          pixelData MUST be set to 0 BEFORE creating the image
	//           also creates a new Image of this size
	Image(unsigned int size_x, unsigned int size_y, int setColorMode);



	//copy constructor
	//Requires:  image is valid
	//Effects: creates a copy of 'image'
	//NOTE: this function is written for you
	Image(const Image& image);



	//destructor
	//Modifies: width, height, pixelData
	//Effects: returns the memory used for the image back to the memory heap
	//NOTE:  this function is written for you
	~Image();



    //assignment operator for Image
    //Requires:  right is a valid Image
	//Effects:  assigns the image on the right to the image on the left
	//NOTE:  this function is written for you
	Image& operator=(const Image& right);


	
    //Required: setColorMode is valid
	//Modifies: width, height, pixelData, colorMode
	//Effects: sets width, height, and colorMode to appropriate parameter
	//         creates pixelData array (i.e., creates the Image) for this size
	void initialize(unsigned int size_x, unsigned int size_y, int setColorMode );



	//Effects: returns false if there is an image; otherwise, true
	//NOTE: to be an actual image it must have
	//      width, height, and pixelData not being 0
	bool empty( );



	//Effects: returns the color of pixel at location [x,y]
	Color getColor(int x, int y) const;



	//Modifies: pixelData
	//Effects: sets pixel at location [x,y] to color
	void setColor(int x, int y, Color color);


	
	//Modifies: colorMode
	//Effects: sets colorMode to appropriate parameter
	void setColorMode(int newColorMode);



	//Effects: returns current colorMode
	int getColorMode( ) const;



	
	//Effects: returns height
	int getHeight() const;



	//Effects: returns width
	int getWidth() const;
	


	//Requires: epsilon >= 0
	//Effects: determines if the images are identical within an 
	//         epsilon range
	//         if any of the widths or heights are 0, return false
	//         if the widths, heights, or colorModes are different, 
	//            return false
	//         if any of the colors in pixelData differ by more than
	//            epsilon, print out the location and the 2 colors,
	//            and return false
	//         otherwise, return true
	// NOTE: great to test your own code to see if it works
	// Prints:  "Empty image"
	//			"different widths"
	//			"different heights"
	//			"different colorMode"
	//          "location        your Color          autograder Color" 
	// Example:   10  215        210 125 125         215 145  145
	// i.e.,      x,y values      RGB values          RGB values
	//			
	bool compareImages(const Image& rhsImage, int epsilon);



	//Modifies: pixelData
	//Effects: scales the color of the entire image by percentages of parameters
    // if (0.7, 1, 1) is passed in
    // it will decrease red by 30%  (i.e., 70% of original amount)
    // green and blue will not be altered
    // if you want blue eliminated you would pass in (1, 1, 0.0)
	void scaleColor(double redAmount, double greenAmount, double blueAmount);



	//Modifies: pixelData
	//Effects: flips the image horizontally, i.e., rotates 180 degrees around the
	//         vertical axis
	void flipLeftRight();



	//Modifies: pixelData
	//Effects: flips the image vertically, i.e., rotates 180 degrees
	//         around the horizontal axis
	void flipUpDown();



	//Modifies: pixelData
	//Effects: duplicates the leftside of the image onto the right-hand side
	//         i.e., hold a mirror at the vertical axis
	void mirrorLeftRight();



	//Modifies: pixelData
	//Effects: duplicates the top portion of the image onto the bottom portion
	//         i.e., hold a mirror at the horizontal axis
	void mirrorUpDown();



	//Modifies: pixelData
	//Effects: for the all pixels between [startx,starty] and
	//         [endx, endy]
	//         if the color distance between the current pixel and
	//         RED is less than 167, then set the amount of red
	//         to be one-fifth of the current red value
	void removeRedEye (int startx, int starty, int endx, int endy);



	//Requires: [xoff, yoff] to be a valid pixel of pixelData array
	//           copyFrom image to be valid and loaded
	//           notCopy to be a valid Color
	//Modifies: pixelData
	//Effects: will copy image "copyFrom" into pixelData 
	//         starting at location [xoff, yoff]
	//         If the color of the pixel within "copyFrom" is <= 
	//         color distance of 20 of color "notCopy", then this pixel
	//         is not copied into pixelData
	//         nothing will be copied that is outside the boundaries
	//         of pixelData of original image
	void insert(int xoff, int yoff, const Image& copyFrom, Color notCopy);



	//Modifies: pixelData
	//Effects: converts the entire image to grayscale by normal
	//         grayscale techniques (see grayscale of Color)
	//Note: this should not change colorMode
	void grayscale();



	//Modifies:  pixelData
	//Effects: we consider blue to be darker than red even if
	// there's the same amount of light reflected off.  To
	// handle this, we need to weigh blue lower, the red a little more
	// and scale green up
	// scale red by 0.30; green by 0.59; blue by 0.11
	// sum together to get the shade of gray
	// NOTE: 0.30 + 0.59 + 0.11 = 1
	// NOTE: this should not change colorMode
	void grayscaleWithLuminance();



	//Modifies: pixelData
    //Effects: ages the image using the sepia algorithm
	//         first change the image to basic grayscale
	//         now add color back in by checking for high, middle, 
	//         and low ranges of color and change them separately
	//         want to make shadows (darkest grays) a bit darker
	//            if red is less than 60, decrease all RGB by 10%
	//         want to make middle grays into a brownish color
	//            if red is less than 190, decrease blue by 20%
	//         want to make lightest grays a bit yellow
	//            othwise, decrease blue by 10%
	//         round double's to int's for the RGB
	void sepiaTint();



	//Requires: numTimes to be positive
	//Effects: will create a new image that is scaled up by the 
	//			passed number of times
	//		    returns this scaled up image
	Image scaleUp(int numTimes) const;



	//Requires: numPixels must be within the size of the image
	//Modifies: pixelData
	//Effects: will blur the image slightly by taking the average
	//          numPixels is the number of pixels to average in all
	//			directions.  If the numPixels is 1, we will average
	//			all pixels in the square defined by the pixel and all
	//          8 of the neighboring pixels:
	//			one pixel left, one pixel right on the x-axis
	//          one pixel above, one pixel below on the y-axis
	//          and the diagonals
	//NOTE:  do NOT blur within the original image
	//       the "blurred" pixels should be assigned into a temp image
	//       such that the "blurred" portion will NOT effect the computations
	//       on the original image
	//       don't forget to round that average
	void simpleBlur(int numPixels);



	//Modifies: width, height, pixelData, colorMode
	//Effects: opens the file, and loads the image
	//Return value of 0 means the bitmap loaded
	//NOTE: this funtion is written for you
	int loadBMP(const std::string &filename);
	int loadBMP(char* filename);



	//Effects: saves the image back to file
    //Return value of 0 means the image saved
	//NOTE: this function is written for you
	int saveBMP(std::string &filename)const;
	int saveBMP(char* filename) const;


    
private:
	int width;
	int height;
	Color** pixelData;   // 2-dim array of pixels
	int colorMode;       // see spec for more discussion
	


	//Effects:   creates an image of size width_x by height_y
	//NOTE:  this function is written for you
	void createImage(int width_x, int height_y);



	//Effects:  makes a copy of the image on the 'right' 
	//NOTE: this function is written for you
	void copyAll(const Image& right);



	//Effects: frees all memory that was allocated for the image
	//         returns the memory back to the memory heap
	//NOTE: this function is written for you
	void freePixelData();

};

#endif
