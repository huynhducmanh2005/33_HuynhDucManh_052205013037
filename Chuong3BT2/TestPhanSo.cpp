#include<iostream>
#include "PhanSo.h"
using namespace std;
int nhapLieu(string s)
{
	int a;
	cout << s;
	cin >> a;
	return a;
}
PhanSo nhapMemDoiTuong()
{
	int t1, m1, t2, m2;
	PhanSo tt;
	t1 = nhapLieu("Ban nhap tu 1: ");
	m1 = nhapLieu("Ban nhap mau 1: ");
	t2 = nhapLieu("Ban nhap tu 2: ");
	m2 = nhapLieu("Ban nhap mau 2:");
	tt.setTu1(t1);
	tt.setMau1(m1);
	tt.setTu2(t2);
	tt.setMau2(m2);
	return tt;
}
void xuatDuLieu(PhanSo tt)
{
	cout << "Phan so 1: " << tt.getTu1() << "/" << tt.getMau1() << endl;
	cout << "Phan so 2: " << tt.getTu2() << "/" << tt.getMau2() << endl;
	cout << "Tong hai phan so: " << tt.tu_tong() << "/" << tt.mau_tong() << endl;
}
void xuatDuLieu(PhanSo* tt)
{
	cout << "Phan so 1: " << tt->getTu1() << "/" << tt->getMau1() << endl;
	cout << "Phan so 2: " << tt->getTu2() << "/" << tt->getMau2() << endl;
	cout << "Tong hai phan so: " << tt->tu_tong() << "/" << tt->mau_tong() << endl;
}
PhanSo * nhapCungDoiTuong()
{
	PhanSo* tt;
	tt = new PhanSo(2, 5, 7, 8);
	return tt;
}
int  menu()
{
	int chon;
	cout << "==========      MENU      ==========\n";
	cout << " 1.=======    Nhap cung    ========  " << endl;
	cout << " 2. =======   Nhap mem     ========  " << endl;
	cout << "  =====  Nhan bat ky thoat  ====  " << endl;
	cout << "        * \"Moi ban chon \" *         " << endl;
	cin >> chon;
	cout << "=========================================" << endl;
	return chon;
}
int main() {
	int chon;
	PhanSo tt1;
	PhanSo* tt2;
	tt2 = new PhanSo();
	bool cung = false;
	do
	{
		cout << "Day la chuong trinh Tinh tong hai phan so\n";
		chon = menu();
		switch (chon)
		{
		case 1:
			tt2 = nhapCungDoiTuong();
			cung = true;
			xuatDuLieu(tt2);
			break;
		case 2:
			tt1 = nhapMemDoiTuong();
			cung = false;
			xuatDuLieu(tt1);
			break;
		default:
			break;
		}
		cout << "Ban co muon tiep tuc khong???(Y/N) \n";
		char a;
		cin >> a;
		if (a != 'Y') {
			return 0;
		}
	} while (chon != 0);
}