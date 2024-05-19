#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <chrono>


using namespace std;
class Employee
{
private:
	string maNhanVien;
	string hoTenNhanVien;
	string ngayVaoLam;
	string soDienThoai;
	int luongCanBan;
public:
	Employee();
	Employee(string, string, string, string, int);
	void setMaNhanVien(string maNhanVien);
	void setHoTenNhanVien(string hoTenNhanVien);
	void setNgayVaoLam(string ngayVaoLam);
	void setSoDienThoai(string soDienThoai);
	void setLuongCanBan(int luongCanBan);
	string getMaNhanVien() const;
	string getHoTenNhanVien() const;
	string getNgayVaoLam() const;
	string getSoDienThoai()const;
	double getLuongCanBan() const;
	virtual void inDanhSach() const;
	virtual double tinhLuong() const = 0;
	friend ostream& operator<<(ostream& out, const Employee& f);


};

