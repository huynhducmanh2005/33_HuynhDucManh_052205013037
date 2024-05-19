#include<iostream>
#include"ChuyenXe.h"
#include"NgoaiThanh.h"
#include"NoiThanh.h"
#include<string>
using namespace std;
string chuanHoaTen2(string& ten)
{
	ten[0] = toupper(ten[0]);
	for (int i = 1; i < ten.size(); i++)
	{
		ten[i] = tolower(ten[i]);
	}
	return ten;
}
void chuanHoaTen1(string& hoTenTaiXe)
{
	string tenTamThoi; string ten = "";
	vector<string> chuoiTen;
	while (hoTenTaiXe[0] == ' ')
	{
		hoTenTaiXe.erase(hoTenTaiXe.begin() + 0);
	}
	for (int i = 0; i < hoTenTaiXe.size(); i++)
	{
		if (hoTenTaiXe[i] != 0)
		{
			tenTamThoi = "";
			int j = i;
			while (j < hoTenTaiXe.size())
			{
				if (hoTenTaiXe[j] == ' ')
				{
					break;
				}
				else
				{
					tenTamThoi = tenTamThoi + hoTenTaiXe[j];
					j++;
				}
			}
			chuoiTen.push_back(tenTamThoi);
			i = j;
		}
	}
	for (int i = 0; i < chuoiTen.size(); i++)
	{
		ten = ten + " " + chuanHoaTen2(chuoiTen[i]);
	}
	ten.erase(ten.begin() + 0);
	hoTenTaiXe = ten;
}
void nhapCung(vector<ChuyenXe*>& danhSachXe)
{
	danhSachXe.push_back(new NoiThanh("2005A", "Tang Thi Thu Hien", "A2-777", 520000, 10, 30));
	danhSachXe.push_back(new NoiThanh("2005A", "Dinh Quoc Dat", "A2-777", 600000, 12, 32));
	danhSachXe.push_back(new NoiThanh("2005A", "Nhat Duy", "A2-777", 700000, 14, 36));
	danhSachXe.push_back(new NgoaiThanh("2904T", "Tran Quang Manh", "A2-089", 200000, "Thai Lan", 2));
	danhSachXe.push_back(new NgoaiThanh("2904T", "Tran Minh Thai", "A2-089", 200000, "China", 2));
	danhSachXe.push_back(new NgoaiThanh("2904T", "Vo Cao Tan Ngoc", "A2-089", 200000, "France", 2));
	cout << "Nhap cung thanh cong !!" << endl;
}

void nhap1(string& maChuyenXe, string& hoTenTaiXe, string& soXe, int& doanhThu)
{
	cin.ignore();
	cout << "Ma so chuyen xe: ";
	getline(cin, maChuyenXe);
	cout << "Ho ten tai xe: ";
	getline(cin, hoTenTaiXe);
	chuanHoaTen1(hoTenTaiXe);
	cout << "So xe: ";
	getline(cin, soXe);
	cout << "Doanh thu: ";
	cin >> doanhThu;
}
NoiThanh nhapNoiThanh()
{
	NoiThanh chuyenXeNoiThanh;
	string hoTenTaiXe, soXe, maChuyenXe;
	int doanhThu, soTuyen, soKmDiDuoc;
	nhap1(maChuyenXe, hoTenTaiXe, soXe, doanhThu);
	cout << "So tuyen: ";
	cin >> soTuyen;
	cout << "So km di duoc: ";
	cin >> soKmDiDuoc;
	chuyenXeNoiThanh.setMaChuyenXe(maChuyenXe);
	chuyenXeNoiThanh.setHoTenTaiXe(hoTenTaiXe);
	chuyenXeNoiThanh.setSoXe(soXe);
	chuyenXeNoiThanh.setSoTuyen(soTuyen);
	chuyenXeNoiThanh.setSoKmDiDuoc(soKmDiDuoc);
	chuyenXeNoiThanh.setDoanhThu(doanhThu);
	return chuyenXeNoiThanh;

}
NgoaiThanh nhapNgoaiThanh()
{

	string hoTenTaiXe, soXe, maChuyenXe;
	int doanhThu;
	string noiDen;// ngoai thanh
	int soNgayDi;// ngoai thanh
	nhap1(maChuyenXe, hoTenTaiXe, soXe, doanhThu);
	cin.ignore();
	cout << "Noi den: ";
	getline(cin, noiDen);
	cout << "So ngay di duoc: ";
	cin >> soNgayDi;
	return NgoaiThanh(maChuyenXe, hoTenTaiXe, soXe, doanhThu, noiDen, soNgayDi);

}

void nhapCacChuyenXe(vector<ChuyenXe*>& danhSachXe)
{
	int luaChon;
	do
	{
		int chon;
		cout << "--------------------------------" << endl;
		cout << "1. Nhap Chuyen xe noi Thanh    |" << endl;
		cout << "2. Nhap Chuyen xe ngoai Thanh  |" << endl;
		cout << "0. Thoat khoi phan nhap        |" << endl;
		cout << "--------------------------------" << endl;
		cout << "Nhap:";
		cin >> chon;
		switch (chon)
		{
		case 0:
		{

			luaChon = 0;
			break;
		}
		case 1:
		{
			int nhap;
			cout << "Chuyen xe noi thanh" << endl;
			cout << "-------------------" << endl;
			do
			{
				danhSachXe.push_back(new NoiThanh(nhapNoiThanh()));
				cout << endl;
				cout << "1. tiep tuc nhap  --- 0. thoat" << endl;
				cout << "Nhap:";
				cin >> nhap;
			} while (nhap != 0);
			break;
		}
		case 2:
		{
			int nhap;
			cout << "Chuyen xe Ngoai Thanh" << endl;
			cout << "---------------------" << endl;
			do
			{
				danhSachXe.push_back(new NgoaiThanh(nhapNgoaiThanh()));
				cout << endl;
				cout << "1. tiep tuc nhap --- 0. thoat" << endl;
				cout << "Nhap:";
				cin >> nhap;
			} while (nhap != 0);
			break;
		}
		default:
		{
			cout << "Khong hop le ! " << endl;
			luaChon = 1;
		}
		}
		if (chon == 1 || chon == 2)
		{
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			cout << "1. Tiep tuc nhap cac loai chuyen xe" << endl;
			cout << "0. Thoat khoi phan nhap" << endl;
			cout << "Nhap:";
			cin >> luaChon;
		}
	} while (luaChon != 0);
}

int  sumNoiThanh(vector<ChuyenXe*> danhSachXe)
{
	int sum = 0;
	for (int i = 0; i < danhSachXe.size(); i++)
	{
		if (NoiThanh* noiThanh = dynamic_cast<NoiThanh*>(danhSachXe[i]))
		{
			sum = sum + danhSachXe[i]->getDoanhThu();
		}
	}
	return sum;
}
int  sumNgoaiThanh(vector<ChuyenXe*> danhSachXe)
{
	int sum = 0;
	for (int i = 0; i < danhSachXe.size(); i++)
	{
		if (NgoaiThanh* ngoaiThanh = dynamic_cast<NgoaiThanh*>(danhSachXe[i]))
		{
			sum = sum + danhSachXe[i]->getDoanhThu();
		}
	}
	return sum;
}
void xuatDanhSach(vector<ChuyenXe*> danhSachXe)
{
	cout << setfill('=') << setw(31) << left << "=" << "* Chuyen xe noi thanh *" << setw(31) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << right << "So tuyen" << setw(10) << right << "So km";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachXe.size(); i++)
	{

		if (NoiThanh* noiThanh = dynamic_cast<NoiThanh*>(danhSachXe[i]))
		{
			cout << *noiThanh << endl;

		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe noi thanh: " << sumNoiThanh(danhSachXe) << endl;
	cout << endl;
	cout << setfill('=') << setw(30) << left << "=" << "* Chuyen xe ngoai thanh *" << setw(30) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << left << "Noi den" << setw(10) << right << "So ngay di";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachXe.size(); i++)
	{

		if (NgoaiThanh* ngoaiThanh = dynamic_cast<NgoaiThanh*>(danhSachXe[i]))
		{
			cout << *ngoaiThanh << endl;
		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe ngoai thanh: " << sumNgoaiThanh(danhSachXe) << endl;
	cout << "\n\n\n";
	cout << "\t\t\t\t Tong danh thu cua Noi Thanh va Ngoai Thanh: " << sumNoiThanh(danhSachXe) + sumNgoaiThanh(danhSachXe) << endl;
}
void menu()
{
	cout << "=========================* Menu *=======================" << endl;
	cout << "1. Nhap cung                                           *\n";
	cout << "2. Nhap mem                                            *\n";
	cout << "3. Xuat danh sach sinh vien                            *\n";
	cout << "0. Thoat                                               *\n";
	cout << "=========================================================" << endl;
}
int main()
{

	vector<ChuyenXe*> danhSachXe;


	int luaChon;
	do
	{
		system("cls");
		menu();

		int chon;
		cout << "Nhap lua chon: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			nhapCung(danhSachXe);
			break;
		}
		case 2:
		{
			nhapCacChuyenXe(danhSachXe);
			break;
		}
		case 3:
		{
			xuatDanhSach(danhSachXe);
			break;
		}

		default:
		{
			luaChon = 0;
		}
		}
		cout << "----------------------------------------------------------" << endl;
		cout << "1. Tiep tuc chuong trinh   0.Thoat thoat khoi chuong trinh" << endl;
		cout << "Chon:";
		cin >> luaChon;
	} while (luaChon != 0);


}
