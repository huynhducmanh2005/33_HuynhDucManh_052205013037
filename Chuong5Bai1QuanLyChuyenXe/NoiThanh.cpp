#include "NoiThanh.h"
#include"ChuyenXe.h"
NoiThanh::NoiThanh() :ChuyenXe()
{
	this->soTuyen = 0;
	this->soKmDiDuoc = 0;
}
NoiThanh::NoiThanh(string maChuyenXe, string hoTenTaiXe, string soXe, int doanhThu, int soTuyen, int soKmDiDuoc) : ChuyenXe(maChuyenXe, hoTenTaiXe, soXe, doanhThu)
{
	this->soTuyen = soTuyen;
	this->soKmDiDuoc = soKmDiDuoc;
}
void NoiThanh::setSoTuyen(int soTuyen)
{
	this->soTuyen = soTuyen;
}
void NoiThanh::setSoKmDiDuoc(int soKmDiDuoc)
{
	this->soKmDiDuoc = soKmDiDuoc;
}
int NoiThanh::getSoTuyen() const
{
	return soTuyen;
}
int NoiThanh::getSoKmDiDuoc() const
{
	return soKmDiDuoc;
}
void NoiThanh::thongTinChuyenXe() const
{
	ChuyenXe::thongTinChuyenXe();
	cout << setfill(' ');
	cout << setw(10) << right << soTuyen << setw(10) << right << soKmDiDuoc;
	cout << setw(15) << right << getDoanhThu();
}
ostream& operator<<(ostream& out, const NoiThanh& f)
{
	//cout << setfill(' ');
	//cout << setw(10) << left << f.getMaChuyenXe() << setw(25) << left << f.getHoTenTaiXe();
	//cout << setw(15) << left << f.getSoXe();
	//cout << setw(10) << right << f.soTuyen << setw(10) << right << f.soKmDiDuoc;
	//cout << setw(15) << right << f.getDoanhThu();
	f.thongTinChuyenXe();
	return out;
}
