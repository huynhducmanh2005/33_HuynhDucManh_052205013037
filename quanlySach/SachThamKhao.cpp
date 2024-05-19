#include "SachThamKhao.h"
#include"Sach.h"
SachThamKhao::SachThamKhao()
{
	this->thue = 0;
}

SachThamKhao::SachThamKhao(string maSach, string ngayNhap, double donGia, int soLuong, string nhaXuatBan, double thue) :Sach(maSach, ngayNhap, donGia, soLuong, nhaXuatBan)
{
	this->thue = thue;
}

void SachThamKhao::setThue(double thue)
{
	this->thue = thue;
}

double SachThamKhao::getThue() const
{
	return thue;
}

double SachThamKhao::thanhTien() const
{
	return getSoLuong() * getDonGia() + thue;
}

void SachThamKhao::inSach() const
{
	Sach::inSach();
	cout << setfill(' ');
	cout << setw(12) << left << thue << setw(15) << right << (long)thanhTien();
}
bool SachThamKhao::isSachNhaXuatBan(string nhaXuatBan) const
{
	if (nhaXuatBan == getNhaXuatBan())
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& out, const SachThamKhao& f)
{
	f.inSach();
	return out;
}
