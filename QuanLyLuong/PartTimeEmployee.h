#pragma once
#include "Employee.h"
using namespace std;
class PartTimeEmployee : public Employee
{
private:
	int soGioLamTrongTuan;
	int luongMotGio;
public:
	PartTimeEmployee();
	PartTimeEmployee(string, string, string, string, int, int, int);
	void setSoGioLamTrongTuan(int soGioLamTrongTuan);
	void setLuongMotGio(int luongMotGio);
	int getSoGioLamTrongTuan() const;
	int getLuongMotGio() const;
	void inDanhSach() const override;
	double tinhLuong() const override;
	friend ostream& operator<<(ostream& out, const PartTimeEmployee& f);
};

