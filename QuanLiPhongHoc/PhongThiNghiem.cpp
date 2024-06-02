#include "PhongThiNghiem.h"

PhongThiNghiem::PhongThiNghiem()
{
	this->chuyenNganh = "###";
	this->sucChua = 0;;
	this->bonRua = 0;
}

PhongThiNghiem::PhongThiNghiem(string maPhong, string dayNha, float dienTich, int bongDen, string chuyenNganh, int sucChua, bool bonRua)
	:PhongHoc(maPhong, dayNha, dienTich, bongDen)
{
	if (chuyenNganh.empty()) {
		throw invalid_argument("Chuyen nganh khong duoc rong");
	}
	this->chuyenNganh = chuyenNganh;
	if (sucChua <= 0) {
		throw invalid_argument("Suc chua phai lon hon 0");
	}
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

void PhongThiNghiem::setBonRua(bool bonRua)
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

bool PhongThiNghiem::getBonRua() const
{
	return 	this->bonRua;
}

void PhongThiNghiem::danhSach() const
{
	PhongHoc::danhSach();
	cout << setfill(' ');
	cout << setw(16) << left << chuyenNganh;
	cout << setw(13) << left << sucChua << setw(14) << left << (getBonRua() ? "Co" : "Khong");
	cout << setw(13) << left << (datChuan() ? "Co" : "Khong") << endl;
}

bool PhongThiNghiem::datChuan() const
{
	return PhongHoc::isDuAnhSang() && getBonRua() > 0;
}

ostream& operator<<(ostream& out, const PhongThiNghiem& f)
{
	f.danhSach();
	return out;
}
