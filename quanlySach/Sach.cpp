#include "Sach.h"

Sach::Sach()
{
	this->maSach = "####";
	this->ngayNhap = "00/00/0000";
	this->donGia = 0;
	this->soLuong = 0;
	this->nhaXuatBan = "####";
}

Sach::Sach(string maSach, string ngayNhap, double donGia, int soLuong, string nhaXuatBan)
{
	this->maSach = maSach;
	this->ngayNhap = ngayNhap;
	this->donGia = donGia;
	this->soLuong = soLuong;
	this->nhaXuatBan = nhaXuatBan;
}

void Sach::setMaSach(string maSach)
{
	this->maSach = maSach;
}

void Sach::setNgayNhap(string ngayNhap)
{
	this->ngayNhap = ngayNhap;
}

void Sach::setDonGia(double donGia)
{
	this->donGia = donGia;
}

void Sach::setSoLuong(int soLuong)
{
	this->soLuong = soLuong;
}

void Sach::setNhaXuatBan(string nhaXuatBan)
{
	this->nhaXuatBan = nhaXuatBan;
}

string Sach::getMaSach() const
{
	return this->maSach;
}

string Sach::getNgayNhap() const
{
	return this->ngayNhap;
}

double Sach::getDonGia() const
{
	return this->donGia;
}

int Sach::getSoLuong() const
{
	return this->soLuong;
}

string Sach::getNhaXuatBan() const
{
	return this->nhaXuatBan;
}
void Sach::inSach() const
{
	cout << setfill(' ');
	cout << setw(10) << left << maSach;
	cout << setw(15) << left << ngayNhap;
	cout << setw(15) << right << donGia;
	cout << setw(12) << right << soLuong;
	cout << setw(3) << left << " ";
	cout << setw(25) << left << nhaXuatBan;
}

ostream& operator<<(ostream& out, const Sach& f)
{
	f.inSach();
	return out;
}
