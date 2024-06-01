#pragma once
#include "quanLyPhongHoc.h"
class PhongThiNghiem :public PhongHoc
{
private:
	string chuyenNganh;
	int sucChua;
	int bonRua;
public:
	PhongThiNghiem();
	PhongThiNghiem(string, string, float, int, string, int, int);
	void setChuyenNganh(string chuyenNganh);
	void setSucChua(int sucChua);
	void setBonRua(int bonRua);
	string getChuyenNganh() const;
	int getSucChua() const;
	int getBonRua() const;
	void danhSach() const override;
	bool datChuan() const override;
	friend ostream& operator<<(ostream& out, const PhongThiNghiem& f);

};

