#include "SachGiaoKhoa.h"
#include"Sach.h"

SachGiaoKhoa::SachGiaoKhoa()
{
	this->tinhTrang = "moi";
}

SachGiaoKhoa::SachGiaoKhoa(string maSach, string ngayNhap, double donGia, int soLuong, string nhaXuatBan, string tinhTrang) :Sach(maSach, ngayNhap, donGia, soLuong, nhaXuatBan)
{
	this->tinhTrang = tinhTrang;
}

void SachGiaoKhoa::setTinhTrang(string tinhTrang)
{
	this->tinhTrang = tinhTrang;
}

string SachGiaoKhoa::getTinhTrang() const
{
	return tinhTrang;
}

double SachGiaoKhoa::thanhTien() const
{
	if (tinhTrang == "moi")
	{
		return getSoLuong() * getDonGia();
	}
	else
	{
		return  getSoLuong() * getDonGia() * 0.5;
	}
}

void SachGiaoKhoa::inSach() const
{
	Sach::inSach();
	cout << setfill(' ');
	cout << setw(12) << left << tinhTrang << setw(15) << right << (long)thanhTien();
}


bool SachGiaoKhoa::isSachNhaXuatBan(string nhaXuatBan) const
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

ostream& operator<<(ostream& out, const SachGiaoKhoa& f)
{
	f.inSach();
	return out;
}
