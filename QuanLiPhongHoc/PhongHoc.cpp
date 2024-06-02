#include "PhongHoc.h"

PhongHoc::PhongHoc()
{
	this->maPhong = "###";
	this->dayNha = "###";
	this->dienTich = 0;
	this->bongDen = 0;
}

PhongHoc::PhongHoc(string maPhong, string dayNha, float dienTich, int bongDen)
{
	if (maPhong.empty()) {
		throw invalid_argument("Ma khong duoc rong");
	}
	this->maPhong = maPhong;
	if (dayNha.empty()) {
		throw invalid_argument("Day nha khong duoc rong");
	}
	this->dayNha = dayNha;
	if (dienTich <= 0) {
		throw invalid_argument("Dien tich phai lon hon 0");
	}
	this->dienTich = dienTich;
	this->bongDen = bongDen;
}

PhongHoc::~PhongHoc()
{
}

void PhongHoc::setMaPhong(string maPhong)
{
	this->maPhong = maPhong;

}

void PhongHoc::setDayNha(string dayNha)
{
	this->dayNha = dayNha;

}

void PhongHoc::setDienTich(float dienTich)
{
	this->dienTich = dienTich;

}

void PhongHoc::setBongDen(int bongDen)
{
	this->bongDen = bongDen;

}

string PhongHoc::getMaPhong() const
{
	return this->maPhong;
}

string PhongHoc::getDayNha() const
{
	return this->dayNha;
}

float PhongHoc::getDienTich() const
{
	return this->dienTich;
}

int PhongHoc::getBongDen() const
{
	return this->bongDen;
}

bool PhongHoc::isDuAnhSang() const
{
	return getBongDen() >= getDienTich() / 10;
}

bool PhongHoc::datChuan() const
{
	return isDuAnhSang();
}

void PhongHoc::danhSach() const
{
	cout << setfill(' ');
	cout << setw(15) << left << maPhong << setw(13) << left << dayNha;
	cout << setw(14) << left << dienTich << setw(14) << left << bongDen;

}

ostream& operator<<(ostream& out, const PhongHoc& f)
{
	f.danhSach();
	return out;

}
