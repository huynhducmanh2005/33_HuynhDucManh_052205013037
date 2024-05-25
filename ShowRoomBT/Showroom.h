#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class Showroom
{
private:
	string ma;
	int namSX;
	double dungTichDongCo;
	long long int triGiaXe;
public:
	Showroom();
	Showroom(string, int, double, long long int);
	~Showroom();
	void setMa(string ma);
	void setNamSX(int namSX);
	void setDungTichDongCo(double dungTichDongCo);
	void setTriGiaXe(long long int triGiaXe);
	string getMa() const;
	int getNamSX() const;
	double getDungTichDongCo() const;
	long long int getTriGiaXe() const;
	virtual void toString() const;
	virtual long long int tinhThue() const = 0;
	virtual long int thueTruocBa() const = 0;
	friend ostream& operator<< (ostream& out, const Showroom& f);

};

