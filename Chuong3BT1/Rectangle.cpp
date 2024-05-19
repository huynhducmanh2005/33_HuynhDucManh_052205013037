#include "Rectangle.h"



void Rectangle::setWidth(int r)
{
	width = r;
}

int Rectangle::getWidth() const
{
	return width;
}

void Rectangle::setHeight(int d)
{
	height = d;
}



int Rectangle::getHeight() const
{
	return height;
}

int Rectangle::area() 
{
	return width * height;
}

Rectangle::Rectangle()
{
	setWidth(0);
	setHeight(0);
}

Rectangle::Rectangle(int d, int r)
{
	setWidth(r);
	setHeight(d);
}

