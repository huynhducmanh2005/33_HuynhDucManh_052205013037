#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class cauHoiTN
{
private:
	string cauHoi;
	string dapAnA;
	string dapAnB;
	string cauTraLoi;
public:
	cauHoiTN();
	cauHoiTN(string, string, string, string);
	void nhap();
	void xuat() const;
	void ghiFile(ofstream& f) const;
	void docFile(ifstream& f);
	bool kiemTra() const;
	friend bool giongNhau(cauHoiTN cau1, cauHoiTN cau2);
};

