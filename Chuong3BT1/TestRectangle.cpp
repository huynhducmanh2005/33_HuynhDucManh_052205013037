#include <iostream>
#include "Rectangle.h"
using namespace std;

int nhapLieu(string s)
{
	int a;
	cout << s;
	cin >> a;
	return a;
}

Rectangle nhapMemDoiTuong()
{
	int d, r;
	Rectangle rect;
	d = nhapLieu("Ban nhap chieu dai: ");
	r = nhapLieu("Ban nhap chieu rong: ");
	rect.setHeight(d);
	rect.setWidth(r);
	return rect;
}
void xuatDuLieu(Rectangle rect)
{
	cout << "Chieu dai: " << rect.getHeight();
	cout << "\n";
	cout << "Chieu rong: " << rect.getWidth();
	cout << "\n";
	cout << "Dien tich: " << rect.area();
	cout << "\n";
}
void xuatDuLieu(Rectangle *rect)
{
	cout << "Chieu dai: " << rect->getHeight();
	cout << "\n";
	cout << "Chieu rong: " << rect->getWidth();
	cout << "\n";
	cout << "Dien tich: " << rect->area();
	cout << "\n";
}
Rectangle * nhapCungDoiTuong()
{
	Rectangle* rect;
	rect = new Rectangle(12, 14);
	return rect;
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
int main()
{
	int chon;
	Rectangle rect1;
	Rectangle* rect2;
	rect2 = new Rectangle();
	bool cung = false;
	do
	{
		cout<< "Day la chuong trinh Tinh dien tich hinh chu nhat\n";
		chon = menu();
		switch (chon)
		{
		case 1:
			rect2 = nhapCungDoiTuong();
			cung = true;
			xuatDuLieu(rect2);
			break;
		case 2:
			rect1 = nhapMemDoiTuong();
			xuatDuLieu(rect1);
			cung = false;
			break;
		default:
			break;
		}
		cout << "Ban co muon tiep tuc khong???(Y/N) \n ";
		char a;
		cin >> a;
		if (a != 'Y') {
			return 0;
		}
	} while (chon != 0);
}
	