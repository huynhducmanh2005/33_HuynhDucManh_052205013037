#include "Showroom.h"

Showroom::Showroom()
{
	this->ma = "###";
	this->namSX = 0;
	this->dungTichDongCo = 0;
	this->triGiaXe = 0;
}

Showroom::Showroom(string ma, int namSX, double dungTichDongCo, long long int triGiaXe)
{
	this->ma = ma;
	this->namSX = namSX;
	this->dungTichDongCo = dungTichDongCo;
	this->triGiaXe = triGiaXe;
}

Showroom::~Showroom()
{
}

void Showroom::setMa(string ma)
{
	this->ma = ma;
}

void Showroom::setNamSX(int namSX)
{
	this->namSX = namSX;
}

void Showroom::setDungTichDongCo(double dungTichDongCo)
{
	this->dungTichDongCo = dungTichDongCo;
}

void Showroom::setTriGiaXe(long long int triGiaXe)
{
	this->triGiaXe = triGiaXe;
}

string Showroom::getMa() const
{
	return this->ma;
}

int Showroom::getNamSX() const
{
	return this->namSX;
}

double Showroom::getDungTichDongCo() const
{
	return this->dungTichDongCo;
}

long long int Showroom::getTriGiaXe() const
{
	return 	this->triGiaXe;
}

void Showroom::toString() const
{
	cout << setfill(' ');
	cout << setw(9) << left << ma << setw(18) << left << namSX;
	cout << setw(17) << left << dungTichDongCo << setw(14) << left << triGiaXe;
}

ostream& operator<<(ostream& out, const Showroom& f)
{
	f.toString();
	return out;
}
