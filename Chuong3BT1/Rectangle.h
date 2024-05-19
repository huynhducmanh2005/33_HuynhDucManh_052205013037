#pragma once
class Rectangle
{
private:
	int width, height;
public:
	void setWidth(int r);
	int getWidth() const;
	void setHeight(int d);
	int getHeight() const;
	int area();
	Rectangle();
	Rectangle(int d, int r);
};

