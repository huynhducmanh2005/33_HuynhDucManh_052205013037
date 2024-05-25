#pragma once
#include "Showroom.h"
class OtoKhach : public Showroom
{
private:
	string loaiXe;
	int soCho;
public:
	OtoKhach();
	OtoKhach(string, int, double, long long int, string, int);
	void setLoaiXe(string loaiXe);
	void setSoCho(int soCho);
	string getLoaiXe() const;
	int getSoCho() const;
	void toString() const override;
	long long int tinhThue() const override;
	long int thueTruocBa() const override;
	friend ostream& operator<<(ostream& out, const OtoKhach& f);

};

