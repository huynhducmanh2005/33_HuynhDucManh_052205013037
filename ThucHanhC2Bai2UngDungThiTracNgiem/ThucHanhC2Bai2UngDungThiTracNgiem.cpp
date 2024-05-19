#include<iostream>
#include"cauHoiTN.h"
#include<fstream>
#include<vector>
#include<string>
using namespace std;
bool giongNhau(cauHoiTN cau1, cauHoiTN cau2)
{
	return cau1.cauHoi == cau2.cauHoi;
}
void menu()
{
	cout << "=====================* MENU *=====================" << endl;
	cout << "* 1.Tao de thi " << endl;
	cout << "* 2.Kiem tra" << endl;
	cout << "* 3.Xuat" << endl;
	cout << "* Nhap so bat ki de thoat" << endl;
	cout << "*================================================*" << endl;
}
void nhapDanhSachCauHoi()
{

	cout << "Nhap so cau : ";
	int soCau, dem;
	cin >> soCau;
	cauHoiTN ojb[100];
	cin.ignore();
	ofstream f;
	f.open("deThi.TTN", ios_base::out);
	for (int i = 0; i < soCau; i++)
	{
		cout << "Cau " << i + 1 << " :" << endl;
		if (i == 0)
		{
			ojb[i].nhap();
		}
		else
		{
			do
			{
				dem = 0;
				ojb[i].nhap();
				for (int j = 0; j < i; j++)
				{
					if (giongNhau(ojb[i], ojb[j]))
					{
						dem++;
					}
				}
				if (dem != 0)
				{
					cout << "Da bi trung!!" << endl;
					cout << "Moi nhap lai!!" << endl;
				}
			} while (dem != 0);

		}
		ojb[i].ghiFile(f);
		if (i < soCau - 1)
		{
			f << endl;
		}
	}
	f.close();
}
void docFile1(vector<cauHoiTN>& v)
{
	cauHoiTN ojb;
	ifstream f;
	f.open("deThi.TTN", ios_base::in);
	while (!f.eof())
	{
		ojb.docFile(f);
		v.push_back(ojb);
	}
	f.close();
}
void xuat1(vector<cauHoiTN> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << i + 1 << ". ";
		v[i].xuat();
		cout << endl;
	}
}
void kiemTra1(vector<cauHoiTN> v)
{
	int soDapAnDung = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cout << i + 1 << ". ";
		if (v[i].kiemTra() == true)
		{
			cout << "Cau tra loi dung!!" << endl;
			soDapAnDung++;
		}
		else
		{
			cout << "Cau tra loi sai!!" << endl;
		}
	}
	cout << "Ban dung duoc " << soDapAnDung << " cau" << endl;
}
int main()
{
	int nhan;
	do
	{
		menu();
		vector<cauHoiTN> v;
		docFile1(v);
		cout << "Moi chon: ";
		int chon;
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
		{
			nhapDanhSachCauHoi();
			docFile1(v);
			break;
		}
		case 2:
		{
			kiemTra1(v);
			break;
		}
		case 3:
		{
			xuat1(v);
			break;

		}
		default:
		{
			nhan = 0;
		}
		}
		if (chon == 1 || chon == 2 || chon == 3)
		{
			cout << "-------------------------------" << endl;
			cout << "1. Tiep tuc   0.Thoat" << endl;
			cout << "Chon: ";
			cin >> nhan;
		}
	} while (nhan != 0);
	return 0;
}