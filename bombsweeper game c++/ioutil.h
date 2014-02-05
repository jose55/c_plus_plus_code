#ifndef IOUTIL_H
#define IOUTIL_H

#include <iostream>
#include <cassert>
#include <cstdlib>

	/****************************
	 * Colored Text Manipulator *
	 ****************************/
	
	//Color enumeration
	enum Color
	{
		BLACK,
		DARK_BLUE,
		DARK_GREEN,
		DARK_CYAN,
		DARK_RED,
		DARK_MAGENTA,
		DARK_YELLOW,
		GRAY,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		YELLOW,
		WHITE
	};

	enum Layer
	{
		BACK,
		FORE
	};

	//manipulator class
	class SetColor
	{
	public:
		SetColor(Color c, Layer l = FORE) : out(NULL), color(c), layer(l) {}

		friend SetColor operator << (std::ostream & out, const SetColor & c);
		template<typename T> std::ostream & operator << (const T & t);

		static bool toggleColor();

	private:
		SetColor(Color c, Layer l, std::ostream & o) : out(&o), color(c), layer(l) {}
		void restore();

		mutable std::ostream * out;
		Color color;
		Layer layer;

		static bool colorOn;
	};

	template<typename T> std::ostream & SetColor::operator << (const T & t)
	{
		assert(out);

		*out << t;

		if(colorOn)
		{
			restore();
		}

		return *out;
	}

	/***************************
	 * ClearScreen Manipulator *
	 ***************************/
	std::ostream & ClearScreen(std::ostream & out);

#endif
