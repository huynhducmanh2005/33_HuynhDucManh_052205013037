#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
class Sach
{
private:
	string maSach;
	string ngayNhap;
	double donGia;
	int soLuong;
	string nhaXuatBan;
public:
	Sach();
	Sach(string, string, double, int, string);
	void setMaSach(string maSach);
	void setNgayNhap(string ngayNhap);
	void setDonGia(double donGia);
	void setSoLuong(int soLuong);
	void setNhaXuatBan(string nhaXuatBan);
	string getMaSach() const;
	string getNgayNhap() const;
	double getDonGia() const;
	int getSoLuong() const;
	string getNhaXuatBan() const;
	virtual double thanhTien() const = 0;
	virtual void inSach() const;
	virtual bool isSachNhaXuatBan(string nhaXuatBan) const = 0;
	friend ostream& operator<<(ostream& out, const Sach& f);
};

