#include "OtoKhach.h"

OtoKhach::OtoKhach()
{
	this->loaiXe = "###";
	this->soCho = 0;
}

OtoKhach::OtoKhach(string ma, int namSX, double dungTichDongCo, long long int triGiaXe, string loaiXe, int soCho) : Showroom(ma, namSX, dungTichDongCo, triGiaXe)
{
	this->loaiXe = loaiXe;
	this->soCho = soCho;
}

void OtoKhach::setLoaiXe(string loaiXe)
{
	this->loaiXe = loaiXe;
}

void OtoKhach::setSoCho(int soCho)
{
	this->soCho = soCho;
}

string OtoKhach::getLoaiXe() const
{
	return this->loaiXe;
}

int OtoKhach::getSoCho() const
{
	return this->soCho;
}
long int OtoKhach::thueTruocBa() const
{
	if (soCho <= 9) {
		return 0.1 * getTriGiaXe();
	}
	else if (loaiXe == "xe ban tai") {
		return 0.06 * getTriGiaXe();
	}
	else {
		return 0.02 * getTriGiaXe();
	}
}
long long int OtoKhach::tinhThue() const
{
	float Thue = 0.1;
	float thueTieuThuDacBiet;
	if (soCho >= 5) {
		thueTieuThuDacBiet = 0.3;
	}
	else if (soCho < 5) {
		thueTieuThuDacBiet = 0.5;
	}

	return (Thue + thueTieuThuDacBiet) * getTriGiaXe() + thueTruocBa();
}

void OtoKhach::toString() const
{
	Showroom::toString();
	cout << setfill(' ');
	cout << setw(16) << left << loaiXe << setw(10) << left << soCho << setw(15) << left << (long long int)tinhThue() << endl;
}
ostream& operator<<(ostream& out, const OtoKhach& f)
{
	f.toString();
	return out;
}
