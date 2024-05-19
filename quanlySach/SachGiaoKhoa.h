#pragma once
#include"Sach.h"
using namespace std;
class SachGiaoKhoa : public Sach
{
private:
	string tinhTrang;
public:
	SachGiaoKhoa();
	SachGiaoKhoa(string, string, double, int, string, string);
	void setTinhTrang(string tinhTrang);
	string getTinhTrang() const;
	double thanhTien() const override;
	void inSach() const override;
	bool isSachNhaXuatBan(string nhaXuatBan) const;
	friend ostream& operator<<(ostream& out, const SachGiaoKhoa& f);

};

