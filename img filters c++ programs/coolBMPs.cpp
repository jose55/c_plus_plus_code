#include <iostream>
using namespace std;
#include "Image.h"
#include "Color.h"	
	  
//Effects:  prints the main menu
void printMenu();

//Effects: gets a valid choice for the current menu
//         This passes in the appropriate printMenu function
int getMenuChoice(void (*)());

//Modifies:  image
//Effects: loads a BMP file into image
// asks for the filename to load
// will call the appropriate member function
void loadBMP(Image& image);

//Requires: image to be loaded
//Effects: asks for the filename you wish to
//       save the image under
//       will call the appropriate member function
void saveBMP(const Image& image);

//Effects: prints the sub-menu for the flip
//  up-down or left-right
void printFlipSubMenu();

//Requires: image to be loaded
//Modifies: image
//Effects: will get how you want to flip the image
//    and call the appropriate member function
void flipSubMenu(Image& image);

//Effects: prints the sub-menu for the mirror
//  horizontal or vertical
void printMirrorSubMenu();

//Requires: image to be loaded
//Modifies: image
//Effects: will get which direction you want image mirrored
//     will call the appropriate member function
void mirrorSubMenu(Image& image);

//Effects: prints the sub-menu for change color
//   change colors, convert to grayscale,
//   conver to grayscale with luminance, or age the image
void printChangeColorSubMenu();

//Requires: image to be loaded
//Modifies: image
//Effects: will get how you want to change the coloration
//   will call the appropriate member function
void changeColorSubMenu(Image& image);

//Requires: image to be loaded
//Modifies: image
//Effects: will ask user the percentages by which
//   they wish the image altered by
//   will call the appropriate member function
void changeColors(Image& image);

//Requires: image to be loaded
//Modifies: image
//Effects: will ask the user for the two points for
//  the boundaries of "eyes"
//   will call the appropriate member function
void removeRedEye(Image& image);

//Requires: image to be loaded, notToCopy to be a valid color
//Modifies: image
//Effects: asks for the location to place the image
//         asks for the filname of the image
//         inserts image in file named at location
//         except for colors of "notToCopy"
//         calls the appropriate member function
void insert(Image& image, Color notToCopy);

//Requires: image to be loaded
//Modifies: image
//Effects: asks for scaleFactor 2--twice as large
//        will call the appropriate member function
//        that will blow up the image
void doScaleUp(Image& image);

//Effects: print a goodbye message
void quit();

//Effects: clears 'cin' and consumes the remainder of the line
void clearInput();

//Effects: will uppercase all the alpha's in str
//     returns this modified str
string toupper(string str);

int main(int argc,char **argv)
{
   int menuChoice;

   Image image;
   const int QUIT = 9;

   do {
      menuChoice = getMenuChoice(printMenu);

	  switch (menuChoice) {
		case 1: loadBMP(image);
			break;
		case 2: saveBMP(image);
			break;
		case 3: flipSubMenu(image);   
			break;
		case 4: mirrorSubMenu(image);
			break;
		case 5: removeRedEye(image);
			break;
		case 6: changeColorSubMenu(image);
			break;
		case 7:  insert(image, BLUE);
			break;
		case 8: doScaleUp(image);
			break;
		case 9: quit();
			break;
		default:  cout << "This is not a valid menu choice " << endl;
	  }
    } while (menuChoice != QUIT);

    return 0;
}

//such that this function could be used with many different
// menu's, the print function was passed in using
// a function pointer
int getMenuChoice(void (*print)()) {
	(*print)();
	int choice;
	
	while (!(cin>>choice)) {
		cin.clear();
		string junk;
		getline(cin, junk);
		(*print)();
	}
	return choice;
}

void flipSubMenu(Image& image)
{
   int choice = getMenuChoice(printFlipSubMenu);
   switch (choice) {
	   case 1: image.flipLeftRight();
		   break;
	   case 2: image.flipUpDown();
		   break;
	   default:  cout << "This is not a valid menu choice " << endl;
	  };
   return;
}

void printFlipSubMenu()
{
	cout << "\nDo you want to FLIP image: " << endl
		 << "   1) left-right " << endl
		 << "   2) up-down" << endl
		 << ">> ";
}

void printMirrorSubMenu()
{
	cout << "\nDo you want to MIRROR image: " << endl
		 << "   1) left-right " << endl
		 << "   2) up-down" << endl
		 << ">> ";
}

void mirrorSubMenu(Image& image)
{
   int choice = getMenuChoice(printMirrorSubMenu);
   switch (choice) {
	   case 1: image.mirrorLeftRight();
		   break;
	   case 2: image.mirrorUpDown();
		   break;
	   default:  cout << "This is not a valid menu choice " << endl;
	  };
   return;
}

void printChangeColorSubMenu()
{
	cout << "\nDo you want to: " << endl
		 << "    1) Change colors" << endl
		 << "    2) Convert to grayscale" << endl
		 << "    3) Convert to grayscale with Luminance" << endl
		 << "    4) Age the image " << endl
		 << ">> ";
}

void changeColorSubMenu(Image& image)
{
	int choice = getMenuChoice(printChangeColorSubMenu);
	switch(choice) {
		case 1: changeColors(image);
			break;
		case 2: image.grayscale();
			break;
		case 3: image.grayscaleWithLuminance();
			break;
		case 4: image.sepiaTint();
			break;
		default:  cout << "This is not a valid menu choice " << endl;
	};
}

void printMenu(){
   cout << "\n\nWelcome to the EECS183 Digital Image Editor" << endl
	    << "-------------------------------------------" << endl
		<< "   1) load an image " << endl
		<< "   2) save the image" << endl
		<< "   3) flip image" << endl
		<< "   4) mirror image" << endl
		<< "   5) remove Red Eye" << endl
		<< "   6) change coloration of image" << endl
		<< "   7) insert another image" << endl
		<< "   8) change size" << endl
		<< "   9) quit " << endl << endl
		<< ">> ";
}

void loadBMP(Image& image){
   string filename;
   cout << "Enter the filename of the BMP image: ";
   cin >> filename;
   string junk;
   getline(cin,junk);
   int val = image.loadBMP(filename);
   if (val == 0) {
      cout << "Image loaded " << endl
           << "width is: " << image.getWidth() << endl
           << "height is: "<< image.getHeight() << endl;
   }
   else {
      cout << "Error in loading image" << endl;
   }

}

void clearInput()
{
	cout << "Input is the wrong datatype" << endl;
	cin.clear();
	string junk;
	getline(cin,junk);
}

void changeColors(Image& image){
	int redPercent, greenPercent, bluePercent;
	cout << "Enter the percentage of red you want: ";
	if (!(cin >> redPercent))  {
		clearInput();
		return;
	}
	double redAmount = redPercent/100.0; 
	cout << "Enter the percentage of green you want: ";
	if (!(cin>>greenPercent)) {
		clearInput();
		return;
	}

	double greenAmount = greenPercent/100.0;
	cout << "Enter the percentage of blue you want: ";
	if (!(cin >> bluePercent)) {
		clearInput();
		return;
	}
	double blueAmount = bluePercent/100.0;

	image.scaleColor(redAmount, greenAmount, blueAmount);
}

void removeRedEye(Image& image) {
	cout << "Enter the x and y values of start: ";
	int startx, starty;
	cin >> startx >> starty;
	if (!(cin )) {
		clearInput();
		return;
	}
	cout << "Enter the x and y values of end pixel: ";
	int endx, endy;
	if (!(cin >> endx >> endy)) {
		clearInput();
		return;
	}
	image.removeRedEye(startx, starty, endx, endy);
}


string toupper(string str)
{
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}

void insert(Image& image, Color notToCopy){
	cout << "Enter the x and y values to place the image: ";
	int xoff,yoff;
	if (!(cin >> xoff >> yoff)) {
		clearInput();
		return;
	}
	cout << "\n Enter the filename of the image to insert: ";
	string filename;
	cin >> filename;
	Image copyFrom;
	int returnVal = copyFrom.loadBMP(filename);
	if (returnVal != 0) {
		cout << "File did not load" << endl;
		return;
	}
	image.insert(xoff, yoff, copyFrom, notToCopy);
}

void doScaleUp(Image & image)
{
	cout << "What is you scale factor? (2 is twice as large) ";
	int factor;
	cin >> factor;
	if (!cin || factor <= 0) {
		cout << "Not a valid scaling" << endl;
		if (!cin) {
			string junk;
			getline(cin, junk);
		}
		return;
	}
	Image newImage = image.scaleUp(factor);
	newImage.simpleBlur(2);
	image = newImage;
}

void saveBMP(const Image& image){
   string filename;
   cout << "Enter filename you want this saved under: ";
   cin >> filename;
   image.saveBMP(filename);
}

void quit(){
   cout << "\n\nThanks for using the EECS183 Digital Image Editor" << endl << endl;
}

