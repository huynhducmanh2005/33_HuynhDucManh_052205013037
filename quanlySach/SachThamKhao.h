#pragma once
#include"Sach.h"
class SachThamKhao :public Sach
{
private:
	double thue;
public:
	SachThamKhao();
	SachThamKhao(string, string, double, int, string, double);
	void setThue(double thue);
	double getThue() const;
	double thanhTien() const override;
	void inSach() const override;
	bool isSachNhaXuatBan(string nhaXuatBan) const;
	friend ostream& operator<<(ostream& out, const SachThamKhao& f);
};

