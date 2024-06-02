#pragma once
#include "PhongHoc.h"
class PhongLiThuyet :public PhongHoc
{
private:
	bool mayChieu;
public:
	PhongLiThuyet();
	PhongLiThuyet(string, string, float, int, bool);
	void setMayChieu(bool mayChieu);
	bool getMayChieu() const;
	bool datChuan() const override;
	void danhSach() const override;
	friend ostream& operator<< (ostream& out, const PhongLiThuyet& f);

};





