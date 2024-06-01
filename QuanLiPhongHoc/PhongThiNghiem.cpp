#include "PhongThiNghiem.h"

PhongThiNghiem::PhongThiNghiem()
{
	this->chuyenNganh = "###";
	this->sucChua = 0;;
	this->bonRua = 0;
}

PhongThiNghiem::PhongThiNghiem(string maPhong, string dayNha, float dienTich, int bongDen, string chuyenNganh, int sucChua, int bonRua)
	:PhongHoc(maPhong, dayNha, dienTich, bongDen)
{
	this->chuyenNganh = chuyenNganh;
	this->sucChua = sucChua;
	this->bonRua = bonRua;
}

void PhongThiNghiem::setChuyenNganh(string chuyenNganh)
{
	this->chuyenNganh = chuyenNganh;

}

void PhongThiNghiem::setSucChua(int sucChua)
{
	this->sucChua = sucChua;

}

void PhongThiNghiem::setBonRua(int bonRua)
{
	this->bonRua = bonRua;

}

string PhongThiNghiem::getChuyenNganh() const
{
	return 	this->chuyenNganh;
}

int PhongThiNghiem::getSucChua() const
{
	return 	this->sucChua;
}

int PhongThiNghiem::getBonRua() const
{
	return 	this->bonRua;
}

void PhongThiNghiem::danhSach() const
{
	PhongHoc::danhSach();
	cout << setfill(' ');
	cout << setw(16) << left << chuyenNganh;
	cout << setw(13) << left << sucChua << setw(14) << left << bonRua;
	cout << setw(13) << left << (datChuan() ? "Co" : "Khong") << endl;
}

bool PhongThiNghiem::datChuan() const
{
	return getBonRua() > 0;
}

ostream& operator<<(ostream& out, const PhongThiNghiem& f)
{
	f.danhSach();
	return out;
}

