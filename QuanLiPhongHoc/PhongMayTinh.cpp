#include "PhongMayTinh.h"

PhongMayTinh::PhongMayTinh()
{
	this->mayTinh = 0;
}

PhongMayTinh::PhongMayTinh(string maPhong, string dayNha, float dienTich, int bongDen, int mayTinh)
	:PhongHoc(maPhong, dayNha, dienTich, bongDen)
{
	if (mayTinh <= 0) {
		throw invalid_argument("So luong may tinh phai lon hon 0");
	}
	this->mayTinh = mayTinh;
}

void PhongMayTinh::setMayTinh(int mayTinh)
{
	this->mayTinh = mayTinh;

}

int PhongMayTinh::getMayTinh() const
{
	return 	this->mayTinh;
}

void PhongMayTinh::danhSach() const
{
	PhongHoc::danhSach();
	cout << setfill(' ');
	cout << setw(15) << left << mayTinh << setw(13) << left << (datChuan() ? "Co" : "Khong") << endl;
}

bool PhongMayTinh::datChuan() const
{
	return PhongHoc::isDuAnhSang() && getMayTinh() >= getDienTich() / 1.5;
}

ostream& operator<<(ostream& out, const PhongMayTinh& f)
{
	f.danhSach();
	return out;
}
