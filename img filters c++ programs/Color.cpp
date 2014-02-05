#include "Color.h"
#include "helperFunctions.h"
#include <cstdlib>
#include <cmath>


void Image::simpleBlur(int numPixels)
{
    Image tempBlure(width, height, colorMode);
    Color testColor;
    int r = 0, g = 0, b = 0, c = 0;
    for (int i = 0; i < height ; i++)
	{
		for(int j = 0 ; j < width; j++)
		{
			tempBlure.setColor(j, i, pixelData[q][i]);
		}
	}
    
    
    for( int w = 0; w <width; w++)
    {
        for( int h= 0; h < height ; h++)
        {
            for(int x = w - numPixels; x <= w+numPixels; x++)
            {
                for (int y = h -numPixels; y <= h+numPixels; y++)
                {
                    if ( y >= 0 && y < height && x >= 0 && x < width)
                    {
                        testColor = tempBlure.getColor(x, y);
                        r = r + testColor.getRed();
                        g = g + testColor.getGreen();
                        b = b + testColor.getBlue();
                        c++;
                    }
                }
            }
            r = roundToInt(r/(count*1.0));
            g = roundToInt(g/(count*1.0));
            b = roundToInt(b/(count*1.0));
            pixelData[w][h].setRed(r);
            pixelData[w][h].setBlue(b);
            pixelData[w][h].setGreen(g);
            c = 0;
            r = 0;
            g = 0;
            b = 0;
        }
    }
}

Color::Color(int colorVal)
{
    blue = (colorVal & 0xff0000) >> 16;
    green = (colorVal & 0xff00) >> 8;
	red = (colorVal & 0xff);
}


int Color::RGB_to_int() const
{
	return ((blue << 16) |(green<<8)|(red));
}



bool Color::operator == (const Color right) const
{
	return (red == right.getRed() && green == right.getGreen() &&
		    blue == right.getBlue());
}

Color Color::operator - (const Color right) const
{
   int redVal, greenVal, blueVal;
   redVal = abs(red - right.getRed());
   greenVal = abs(green - right.getGreen());
   blueVal = abs(blue - right.getBlue());
   return Color(redVal, greenVal, blueVal);
}

bool Color::operator <= (int value) const
{
   return (red <= value && green <= value && blue <= value);
}

