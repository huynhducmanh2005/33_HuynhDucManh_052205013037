#include "PhongLiThuyet.h"

PhongLiThuyet::PhongLiThuyet()
{
	this->mayChieu = 0;
}

PhongLiThuyet::PhongLiThuyet(string maPhong, string dayNha, float dienTich, int bongDen, int mayChieu)
	:PhongHoc(maPhong, dayNha, dienTich, bongDen)
{
	this->mayChieu = mayChieu;
}

void PhongLiThuyet::setMayChieu(int mayChieu)
{
	this->mayChieu = mayChieu;

}

int PhongLiThuyet::getMayChieu() const
{
	return this->mayChieu;
}

bool PhongLiThuyet::datChuan() const
{
	return getMayChieu() > 0;
}

void PhongLiThuyet::danhSach() const
{
	PhongHoc::danhSach();
	cout << setfill(' ');
	cout << setw(15) << left << mayChieu << setw(13) << left << (datChuan() ? "Co" : "Khong") << endl;

}

ostream& operator<<(ostream& out, const PhongLiThuyet& f)
{
	f.danhSach();
	return out;
}
