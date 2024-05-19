#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;
class Fraction1
{
private:
	int numerator;
	int denominator;
public:
	friend istream& operator>>(istream& in, Fraction1& nhap);
	friend ostream& operator<<(ostream& out, Fraction1& xuat);
	Fraction1();
	Fraction1(int tu, int mau);
	void setNumerator(int x);
	void setDenominator(int x);
	int getNumerator() const;
	int getDenominator() const;
	Fraction1 toiGian(int x, int y);
	Fraction1 operator+(const Fraction1& phanSo);
	Fraction1 operator-(const Fraction1& phanSo);
	Fraction1 operator*(const Fraction1& phanSo);
	Fraction1 operator/(const Fraction1& phanSo);
	bool operator==(const Fraction1& phanSo);
	bool operator!=(const Fraction1& phanSo);
	bool operator>=(const Fraction1& phanSo);
	bool operator<=(const Fraction1& phanSo);

};

