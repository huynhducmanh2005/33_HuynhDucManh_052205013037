#pragma once
#include <iostream>
using namespace std;
class Point
{
private:
	float x, y;
public:
	Point(float x, float y) { this->x = x; this->y = y; }
	Point() {}
	friend ostream& operator<<(ostream& os, Point& p);
	friend istream& operator>>(istream& is, Point& p);
	//bool operator<(Point p2); //so sanh (*this < p2)
	friend bool operator<(Point p1, Point p2);
	float khoangcach(Point p2); // tinh khoang cach tu *this toi p2
};

