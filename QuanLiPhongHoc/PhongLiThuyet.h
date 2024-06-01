#pragma once
#include "quanLyPhongHoc.h"
class PhongLiThuyet :public PhongHoc
{
private:
	int mayChieu;
public:
	PhongLiThuyet();
	PhongLiThuyet(string, string, float, int, int);
	void setMayChieu(int mayChieu);
	int getMayChieu() const;
	bool datChuan() const override;
	void danhSach() const override;
	friend ostream& operator<< (ostream& out, const PhongLiThuyet& f);

};

