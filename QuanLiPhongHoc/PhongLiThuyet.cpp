#include "PhongLiThuyet.h"

PhongLiThuyet::PhongLiThuyet()
{
	this->mayChieu = 0;
}

PhongLiThuyet::PhongLiThuyet(string maPhong, string dayNha, float dienTich, int bongDen, bool mayChieu)
	:PhongHoc(maPhong, dayNha, dienTich, bongDen)
{
	this->mayChieu = mayChieu;
}

void PhongLiThuyet::setMayChieu(bool mayChieu)
{
	this->mayChieu = mayChieu;

}

bool PhongLiThuyet::getMayChieu() const
{
	return this->mayChieu;
}

bool PhongLiThuyet::datChuan() const
{
	return PhongHoc::isDuAnhSang() && getMayChieu() > 0;
}

void PhongLiThuyet::danhSach() const
{
	PhongHoc::danhSach();
	cout << setfill(' ');
	cout << setw(15) << left << (getMayChieu() ? "Co" : "Khong") << setw(13) << left << (datChuan() ? "Co" : "Khong") << endl;

}

ostream& operator<<(ostream& out, const PhongLiThuyet& f)
{
	f.danhSach();
	return out;
}
