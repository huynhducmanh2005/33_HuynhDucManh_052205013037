#include "ChuyenXe.h"
using namespace std;
ChuyenXe::ChuyenXe()
{
	this->maChuyenXe = "####";
	this->hoTenTaiXe = "####";
	this->soXe = "####";
	this->doanhThu = 0;
}
ChuyenXe::ChuyenXe(string maChuyenXe, string hoTenTaiXe, string soXe, int doanhThu)
{
	this->maChuyenXe = maChuyenXe;
	this->hoTenTaiXe = hoTenTaiXe;
	this->soXe = soXe;
	this->doanhThu = doanhThu;
}
void ChuyenXe::setMaChuyenXe(string maChuyenXe)
{
	this->maChuyenXe = maChuyenXe;
}
void ChuyenXe::setHoTenTaiXe(string hoTenTaiXe)
{
	this->hoTenTaiXe = hoTenTaiXe;
}
void ChuyenXe::setSoXe(string soXe)
{
	this->soXe = soXe;
}

void ChuyenXe::setDoanhThu(int doanhThu)
{
	this->doanhThu = doanhThu;
}

string ChuyenXe::getMaChuyenXe() const
{
	return this->maChuyenXe;
}

string ChuyenXe::getHoTenTaiXe() const
{
	return this->hoTenTaiXe;
}

string ChuyenXe::getSoXe() const
{
	return this->soXe;
}

int ChuyenXe::getDoanhThu() const
{
	return this->doanhThu;
}

void ChuyenXe::thongTinChuyenXe() const
{
	cout << setfill(' ');
	cout << setw(10) << left << getMaChuyenXe() << setw(25) << left << getHoTenTaiXe();
	cout << setw(15) << left << getSoXe();
}

ostream& operator<<(ostream& out, const ChuyenXe& f)
{
	cout << setfill(' ');
	cout << setw(10) << left << f.getMaChuyenXe() << setw(25) << left << f.getHoTenTaiXe();
	cout << setw(15) << left << f.getSoXe();
	cout << setw(15) << right << f.getDoanhThu() << endl;
	return out;
}
