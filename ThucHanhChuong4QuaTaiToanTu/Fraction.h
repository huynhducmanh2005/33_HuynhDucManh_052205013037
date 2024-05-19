#pragma once
#include <fstream>
using namespace std;

class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int demoninator);
	Fraction(int n);
	~Fraction();
private:
	int numerator; //Tu so
	int denominator; //Mau so
public:
    Fraction operator +(const Fraction&) const;
    Fraction operator -(const Fraction&) const;
    Fraction operator *(const Fraction&) const;
    Fraction operator /(const Fraction&) const;
    
    bool operator ==(const Fraction&) const;
    bool operator !=(const Fraction&) const;
    bool operator <(const Fraction&) const;
    bool operator >(const Fraction&) const;
    bool operator <=(const Fraction&) const;
    bool operator >=(const Fraction&) const;
    
    friend ostream& operator <<(ostream&, const Fraction&);
    friend istream& operator >>(istream&, Fraction&);
   
};
