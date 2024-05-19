#include "Fraction.h"
#include <cstdlib>
#include <ctime>
using namespace std;
Fraction::Fraction() : numerator(0), denominator(1)
{
}


Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
{
}

Fraction::Fraction(int n)
{
	if (n > 0)
	{
		numerator = rand() % n + 1;
		denominator = rand() % n + 1;
	}
	else
	{
		numerator = 0;
		denominator = 1;
	}
}

Fraction::~Fraction()
{
}

Fraction Fraction::operator +(const Fraction& other) const
{
	Fraction f(0);
	f.numerator = this->numerator * other.denominator + this->denominator * other.numerator;
	f.denominator = this->denominator * other.denominator;
	return f;
}

Fraction Fraction::operator -(const Fraction& other) const
{
	Fraction f(0);
	f.numerator = (this->numerator * other.denominator - this->denominator * other.numerator);
	f.denominator = this-> denominator * other.denominator;
	return f;

}

Fraction Fraction::operator *(const Fraction& other) const
{
	Fraction f(0);
	f.numerator = (this->numerator * other.numerator);
	f.denominator = this->denominator * other.denominator;
	return f;
}

Fraction Fraction::operator /(const Fraction& other) const
{
	Fraction f(0);
	f.numerator = (this->numerator * other.denominator);
	f.denominator = this->denominator * other.numerator;
	return f;
}

bool Fraction::operator ==(const Fraction& other) const
{
	return this->numerator * other.denominator == this->denominator * other.numerator;
}

bool Fraction::operator !=(const Fraction& other) const
{
	return this->numerator * other.denominator != this->denominator * other.numerator;
}

bool Fraction::operator<(const Fraction& other) const
{
	return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>(const Fraction& other) const
{
	return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator >=(const Fraction& other) const
{
	return this->numerator * other.denominator >= this->denominator * other.numerator;
}

bool Fraction::operator <=(const Fraction& other) const
{
	return this->numerator * other.denominator <= this->denominator * other.numerator;
}

ostream& operator <<(ostream& out, const Fraction& f)
{
	out << f.numerator << "/" << f.denominator;
	return out;
}

istream& operator >>(istream& in, Fraction& f)
{
	in >> f.numerator >> f.denominator;
	return in;
}
