#include "NgoaiThanh.h"
#include"ChuyenXe.h"
NgoaiThanh::NgoaiThanh() :ChuyenXe()
{
	this->noiDen = "####";
	this->soNgayDi = 0;
}
NgoaiThanh::NgoaiThanh(string maChuyenXe, string hoTenTaiXe, string soXe, int doanhThu, string noiDen, int soNgayDi) :ChuyenXe(maChuyenXe, hoTenTaiXe, soXe, doanhThu)
{
	this->noiDen = noiDen;
	this->soNgayDi = soNgayDi;
}

void NgoaiThanh::setNoiDen(string noiDen)
{
	this->noiDen = noiDen;

}

void NgoaiThanh::setSoNgayDi(int soNgayDi)
{
	this->soNgayDi = soNgayDi;
}

string NgoaiThanh::getNoiDen() const
{
	return noiDen;
}

int NgoaiThanh::getSoNgayDi() const
{
	return soNgayDi;
}

void NgoaiThanh::thongTinChuyenXe() const
{
	ChuyenXe::thongTinChuyenXe();
	cout << setfill(' ');
	cout << setw(10) << left << noiDen << setw(10) << right << soNgayDi;
	cout << setw(15) << right << getDoanhThu();
}

ostream& operator<<(ostream& out, const NgoaiThanh& f)
{
	//out << setfill(' ');
	//out << setw(10) << left << f.getMaChuyenXe() << setw(25) << left << f.getHoTenTaiXe();
	//out << setw(15) << left << f.getSoXe();
	//out << setw(10) << left << f.noiDen << setw(10) << right << f.soNgayDi;
	//out << setw(15) << right << f.getDoanhThu();
	f.thongTinChuyenXe();
	return out;
}
