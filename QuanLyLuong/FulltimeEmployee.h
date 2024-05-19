#pragma once
#include "Employee.h"
using namespace std;
class FullTimeEmployee : public Employee
{
private:
	double heSoLuong;
	int soNamKinhNghiem;
public:
	FullTimeEmployee();
	FullTimeEmployee(string, string, string, string, int, double, int);
	void setHeSoLuong(double heSoLuong);
	void setSoNamKinhNghiem(int soNamKinhNghiem);
	int getHeSoLuong() const;
	int getSoNamKinhNghiem() const;
	void inDanhSach() const override;
	double tinhLuong() const override;
	friend ostream& operator<<(ostream& out, const FullTimeEmployee& f);

};

