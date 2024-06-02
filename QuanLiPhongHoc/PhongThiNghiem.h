#pragma once
#include "PhongHoc.h"
class PhongThiNghiem :public PhongHoc
{
private:
	string chuyenNganh;
	int sucChua;
	bool bonRua;
public:
	PhongThiNghiem();
	PhongThiNghiem(string, string, float, int, string, int, bool);
	void setChuyenNganh(string chuyenNganh);
	void setSucChua(int sucChua);
	void setBonRua(bool bonRua);
	string getChuyenNganh() const;
	int getSucChua() const;
	bool getBonRua() const;
	void danhSach() const override;
	bool datChuan() const override;
	friend ostream& operator<<(ostream& out, const PhongThiNghiem& f);

};

