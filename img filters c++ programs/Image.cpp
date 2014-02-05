#include "Image.h"
#include "helperFunctions.h"

#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;




Image::Image(const Image& right)
{
	copyAll(right);
}

Image& Image::operator=(const Image& right)
{
	if (this != &right) {
		freePixelData();
		copyAll(right);
	}
	return *this;
}

void Image::copyAll(const Image& right)
{
	width = right.width;
	height = right.height;
	colorMode = right.colorMode;
	pixelData = NULL;
	createImage(width, height);
	
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			pixelData[x][y] = right.pixelData[x][y];
		}
	}
}

void Image::freePixelData()
{
	if (pixelData == NULL) // if already freed
		return;
	for (int x = 0; x < width; x++) {
		delete [] pixelData[x];
	}
	width = 0;
	height = 0;
	delete [] pixelData;
	pixelData = NULL;
}

void Image::createImage(int width_x, int height_y)
{
    width = width_x;
    height = height_y;
	if (pixelData!=NULL)
		freePixelData();
	if (width == 0 || height == 0) {
	    return;
	}

	pixelData = new Color* [width];  // array of Pixel*
	for (int x = 0; x < width; x++) {
		pixelData[x] = new Color [height];  // this is 2nd dimension of pixelData
	}
}


Image::~Image()
{
    freePixelData();
}


int Image::loadBMP(char* filename)
{
	string name = filename;
	return loadBMP(name);
}

int Image::loadBMP(const std::string &filename)
{
	ifstream file;
	unsigned int filesize, data_offset, i, offset_row;
	unsigned int fill_null, count_row;
	unsigned char buffer[4];
	int x, y;

	file.open(filename.c_str() , ios_base::in | ios_base::binary);
	if(file.fail()){
		cerr << "[Image::loadBmp] Error opening " << filename << endl;
		return -1;
	}
	file.seekg(0, ios_base::beg);
	file.read((char*)buffer, 2);
	if(file.fail()){
		cerr << "[Image::loadBmp] Error reading " << filename << endl;
		return -1;
	}

	if(buffer[0] != 'B' || buffer[1] != 'M'){
		cerr << "[Image::loadBmp] File is not a bitmap file" << endl;
		return -1;
	} 

	freePixelData(); // clear out array in case something is there already

	// file length : offset 2
	file.read((char *)&filesize, 4);
	// reserved: offset 6
	file.read((char *)&i, 4);
	// data offset: offset 10
	file.read((char *)&data_offset, 4);
	
	// Bitmap info header
	bmp_info_header info;
	file.read((char *)&info, BMP_INFO_SIZE);

	if(info.compression != 0){
		cerr << "[Image::loadBmp] Compressed bitmap is not supported" << endl;
		return -1;
	}
	width = info.width;
	height = info.height;

        createImage(width, height);

	if(info.bpp == 24){
		fill_null = 3 - (width * 3 - 1) % 4;
		count_row = width * 3 + fill_null;
		for (y = height-1; y >= 0; y--) {
			file.seekg(data_offset, ios_base::beg);
			offset_row = width * y;
			for(x = 0; x < width; x++){
				file.read((char*)buffer, 3);
                pixelData[x][y] = Color((((int)buffer[0]) << 16) | (((int)buffer[1]) << 8) | (int)buffer[2]);
				//pixelData[x][y] = Color((((int)buffer[0]) ) | (((int)buffer[1]) << 8) | (int)buffer[2] << 16);
			}
			data_offset += count_row;
		}
		colorMode = TRUE_COLOR_24BPP;
		cout << width << "*" << height << " 24bpp true color" << endl;
	} else if(info.bpp == 8){
		fill_null = 3 - (width - 1) % 4;
		count_row = width + fill_null;
		for(y = 0; y < height; y ++){
			file.seekg(data_offset, ios_base::beg);
			offset_row = width * y;
			for(x = 0; x < width; x++){
				file.read((char *)buffer, 1);
				pixelData[x][y] = Color((int)buffer[0]);
			}
			data_offset += count_row;
		}
		colorMode = GRAY_8BPP;
		cout << width << "*" << height << " 8bpp gray scale" << endl;
	}
	if(file.fail()){
		cerr << "[Image::loadBmp] Error reading file." << endl;
		return -1;
	}
	return 0;
}

int Image::saveBMP(char* filename) const
{
	string name = filename;
	return saveBMP(name);
}

int Image::saveBMP(std::string &filename) const
{
	ofstream file;

	unsigned char header[] = "BM", buffer[4];
	unsigned int filesize, data_offset;
	unsigned int i, offset, offset_row, fill_dword, count_row;
    int x, y;

	bmp_info_header info;
	info.width = width;
	info.height = height;

	if(colorMode == GRAY_8BPP){
		info.bpp = 8;
		data_offset = 14 + BMP_INFO_SIZE + 256*4;
		fill_dword = 3 - (width - 1) % 4;
		count_row = width + fill_dword;
	} else if(colorMode == TRUE_COLOR_24BPP){
		info.bpp = 24;
		data_offset = 14 + BMP_INFO_SIZE;
		fill_dword = 3 - (width * 3 - 1) % 4;
		count_row = width * 3 + fill_dword;
	} else {
		cerr << "[Image::saveBmp] Color mode " << colorMode << " is not supported" << endl;
		return -1;
	}
	info.image_size = count_row * height;
	filesize = data_offset + info.image_size; 

	file.open(filename.c_str() , ios::out | ios::binary | ios::trunc);
	if(file.fail()){
		cerr << "[Image::saveBmp] Error opening " << filename << endl;
		return -1;
	}
	file.write((char*)header, 2);
	file.write((char *)&filesize, 4);
	i = 0;
	file.write((char *)&i, 4);
	file.write((char *)&data_offset, 4);
	file.write((char *)&info, BMP_INFO_SIZE);
	if(colorMode == GRAY_8BPP){
		unsigned char pallet[256 * 4];
		for(i = 0;i < 256;i++){
			offset = i << 2;
			pallet[offset] = (unsigned char)i; // Blue
			pallet[offset + 1] = (unsigned char)i; // Green
			pallet[offset + 2] = (unsigned char)i; // Red
			pallet[offset + 3] = 0;
		}
		file.write((char *)pallet, 256 * 4);
	}
	i = 0;
	for(y = height-1; y >=0; y--){
		offset_row = width * y;
		for(x = 0; x < width; x++){
			if(colorMode == GRAY_8BPP){
				buffer[0]= (unsigned char)pixelData[x][y].getRed();
				file.write((char *)buffer, 1);
			} else if(colorMode == TRUE_COLOR_24BPP){
				buffer[0] = (pixelData[x][y].RGB_to_int() & 0xff0000)>> 16; // Blue
				buffer[1] = (pixelData[x][y].RGB_to_int() & 0xff00) >> 8; // Green
				buffer[2] = (pixelData[x][y].RGB_to_int() & 0xff); // Red
				
				file.write((char *)buffer, 3);
			}
		}
		if(fill_dword)
			file.write((char *)&i, fill_dword);
	}
	if(file.fail()){
		cerr << "[Image::saveBmp] Error writing " << filename << endl;
		return -1;
	}
	return 0;
}


bmp_info_header::bmp_info_header(void)
{
	info_size = 40;
	width = 0;
	height = 0;
	plane = 1;
	bpp = 8;
	compression = 0;
	image_size = 0;
	ppm_x = 0;
	ppm_y = 0;
	colors = 0;
	important_colors = 0;
}

