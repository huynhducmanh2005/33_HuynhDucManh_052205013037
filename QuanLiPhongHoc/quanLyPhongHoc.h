#pragma once
#include <string>
#include <iostream>
#include<vector>
#include<iomanip>
#include <algorithm>


using namespace std;
class PhongHoc
{
protected:
	string maPhong;
	string dayNha;
	float dienTich;
	int bongDen;
public:
	PhongHoc();
	PhongHoc(string, string, float, int);
	~PhongHoc();
	void setMaPhong(string maPhong);
	void setDayNha(string dayNha);
	void setDienTich(float dienTich);
	void setBongDen(int bongDen);
	string getMaPhong() const;
	string getDayNha() const;
	float getDienTich() const;
	int getBongDen() const;
	virtual bool datChuan() const;
	virtual void danhSach() const;
	friend ostream& operator<< (ostream& out, const PhongHoc& f);


};

