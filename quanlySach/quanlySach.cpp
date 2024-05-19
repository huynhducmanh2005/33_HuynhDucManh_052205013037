#include<iostream>
#include"Sach.h"
#include"SachGiaoKhoa.h"
#include"SachThamKhao.h"
#include<string>
using namespace std;
void khungSach()
{
	cout << setfill(' ');
	cout << setw(10) << left << "Ma Sach";
	cout << setw(15) << left << "Ngay nhap";
	cout << setw(15) << right << "Don Gia";
	cout << setw(12) << right << "So Luong";
	cout << setw(3) << left << " ";
	cout << setw(25) << left << "Nha xuat ban";
}
void checkNgayNhap(string& ngayNhap)//29/04/2005
{
	if (ngayNhap[1] == '/')
	{
		ngayNhap = "0" + ngayNhap;
	}
	if (ngayNhap[4] == '/')
	{
		ngayNhap = ngayNhap.insert(3, "0");
	}
}
void nhapCung(vector < Sach*>& mangSach)
{
	mangSach.push_back(new SachGiaoKhoa("001", "12/04/2016", 20000, 100, "Vo Cao Tan Ngoc", "moi"));
	mangSach.push_back(new SachGiaoKhoa("002", "29/07/2018", 10000, 100, "Dinh Quoc Dat", "cu"));
	mangSach.push_back(new SachGiaoKhoa("003", "20/05/2012", 90000, 100, "Tang Thi Thu Hien", "moi"));
	mangSach.push_back(new SachGiaoKhoa("004", "12/04/2017", 24000, 100, "Tran Minh Thai", "cu"));
	mangSach.push_back(new SachGiaoKhoa("005", "05/12/2023", 12000, 100, "Dinh Quoc Dat", "moi"));
	mangSach.push_back(new SachThamKhao("006", "14/09/2023", 30000, 100, "Nguyen Thanh Long", 2000));
	mangSach.push_back(new SachThamKhao("007", "12/01/2023", 89000, 100, "Ngo Nguyen Quynh Nhu", 1000));
	mangSach.push_back(new SachThamKhao("008", "28/09/2023", 10000, 100, "Dinh Quoc Dat", 3000));
	mangSach.push_back(new SachThamKhao("009", "15/04/2023", 55000, 100, "Nguyen Huu Bui Lam Huy", 5000));
	mangSach.push_back(new SachThamKhao("0010", "01/07/2023", 66000, 100, "Bui Tien Vy", 1000));

}
void nhapSach(string& maSach, string& ngayNhap, double& donGia, int& soLuong, string& nhaXuatBan)
{
	cin.ignore();
	cout << "Nhap ma sach: ";
	getline(cin, maSach);
	cout << "Nhap ngay nhap: ";//2/0/2005
	do
	{
		getline(cin, ngayNhap);
		if (ngayNhap.size() < 8 || ngayNhap.size() > 10)
		{
			cout << "Khong hop le !!" << endl;
			cout << "Nhap lai ngay nhap: ";
		}
	} while (ngayNhap.size() < 8 || ngayNhap.size() > 10);
	checkNgayNhap(ngayNhap);
	cout << "Nhap don gia: ";
	cin >> donGia;
	cout << "Nhap so luong: ";
	cin >> soLuong;
	cin.ignore();
	cout << "Nhap nha xuat ban: ";
	getline(cin, nhaXuatBan);
}
SachGiaoKhoa nhapSachGiaoKhoa()
{
	string maSach;
	string ngayNhap;
	double donGia;
	int soLuong;
	string nhaXuatBan;
	string tinhTrang;
	nhapSach(maSach, ngayNhap, donGia, soLuong, nhaXuatBan);
	cout << "Nhap tinh trang: ";
	do
	{
		getline(cin, tinhTrang);
		string x = tinhTrang;
		while (x[x.size() - 1] == ' ')
		{
			x.erase(x.begin() + (x.size() - 1));
		}
		while (x[0] == ' ')
		{
			x.erase(x.begin() + 0);
		}
		for (int i = 0; i < x.size(); i++)
		{
			x[i] = tolower(x[i]);
		}
		tinhTrang = x;
		if (tinhTrang != "moi" && tinhTrang != "cu")
		{
			cout << "Khong hop le! " << endl;
			cout << "Nhap lai tinh trang cua sach: ";
		}
	} while (tinhTrang != "moi" && tinhTrang != "cu");
	return SachGiaoKhoa(maSach, ngayNhap, donGia, soLuong, nhaXuatBan, tinhTrang);
}
SachThamKhao nhapSachThamKhao()
{
	string maSach;
	string ngayNhap;
	double donGia;
	int soLuong;
	string nhaXuatBan;
	string tinhTrang;
	double thue;
	nhapSach(maSach, ngayNhap, donGia, soLuong, nhaXuatBan);
	cout << "Nhap thue: ";
	cin >> thue;
	return SachThamKhao(maSach, ngayNhap, donGia, soLuong, nhaXuatBan, thue);
}
void nhapCacLoaiSach(vector<Sach*>& mangSach)
{
	int luaChon;
	do
	{
		int chon;
		cout << "--------------------------------" << endl;
		cout << "1. Nhap sach giao khoa         |" << endl;
		cout << "2. Nhap sach tham khao         |" << endl;
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
			cout << "Sach Giao Khoa" << endl;
			cout << "--------------" << endl;
			do
			{
				mangSach.push_back(new SachGiaoKhoa(nhapSachGiaoKhoa()));
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
			cout << "Sach Tham Khao" << endl;
			cout << "--------------" << endl;
			do
			{
				mangSach.push_back(new SachThamKhao(nhapSachThamKhao()));
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
			cout << "1. Tiep tuc nhap cac loai sach" << endl;
			cout << "0. Thoat khoi phan nhap" << endl;
			cout << "Nhap:";
			cin >> luaChon;
		}
	} while (luaChon != 0);
}
double tongSachGiaoKhoa(vector<Sach*>mangSach)
{
	double sum = 0;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (SachGiaoKhoa* sachGiaoKhoa = dynamic_cast<SachGiaoKhoa*>(mangSach[i]))
		{

			sum = sum + mangSach[i]->thanhTien();

		}
	}
	return sum;
}

double tongSachThamKhao(vector<Sach*>mangSach)
{
	double sum = 0;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (SachThamKhao* sachThamKhao = dynamic_cast<SachThamKhao*>(mangSach[i]))
		{

			sum = sum + mangSach[i]->thanhTien();

		}
	}
	return sum;
}
void xuatNXBSachGiaoKhoa(vector<Sach*>mangSach)
{
	string nhaXuatBanCanTim;
	cout << "Nhap nha xuat ban can tim: ";
	getline(cin, nhaXuatBanCanTim);
	cout << endl;
	cout << setfill('=') << setw(65) << right << "* Sach giao khoa *" << setw(42) << right << "=" << endl;
	cout << endl;
	khungSach();
	cout << setw(12) << left << "Tinh trang " << setw(15) << right << "Thanh tien" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (SachGiaoKhoa* sachGiaoKhoa = dynamic_cast<SachGiaoKhoa*>(mangSach[i]))
		{
			if (mangSach[i]->isSachNhaXuatBan(nhaXuatBanCanTim))
			{
				mangSach[i]->inSach();
			}
		}
	}
	cout << setfill('-') << setw(107) << "-" << endl;
	cout << endl;
	cout << "Tong thanh tien sach Giao Khoa: " << (long)(tongSachGiaoKhoa(mangSach)) << endl;
}
void xuatNXBSachThamKhao(vector<Sach*>mangSach)
{
	string nhaXuatBanCanTim;
	cout << "Nhap nha xuat ban can tim: ";
	getline(cin, nhaXuatBanCanTim);
	cout << endl;
	cout << setfill('=') << setw(65) << right << "* Sach tham khao *" << setw(42) << right << "=" << endl;
	cout << endl;
	khungSach();
	cout << setw(12) << left << "Thue" << setw(15) << right << "Thanh tien" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (SachThamKhao* sachThamKhao = dynamic_cast<SachThamKhao*>(mangSach[i]))
		{
			if (mangSach[i]->isSachNhaXuatBan(nhaXuatBanCanTim))
			{
				mangSach[i]->inSach();
			}
		}
	}
	cout << setfill('-') << setw(107) << "-" << endl;
	cout << endl;
	cout << "Tong thanh tien sach Tham Khao: " << (long)(tongSachThamKhao(mangSach)) << endl;
}
void tongDonGiasachThamKhao(vector<Sach*>mangSach)
{
	double trungBinhCong = 0;
	int count = 0;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (SachThamKhao* sachThamKhao = dynamic_cast<SachThamKhao*>(mangSach[i]))
		{
			trungBinhCong += mangSach[i]->getDonGia();
			count++;
		}
	}
	trungBinhCong = trungBinhCong / count;
	cout << "Trung binh cong don gia cua sach giao khoa la: " << trungBinhCong << endl;
}
void xuatDanhSach(vector<Sach*> mangSach)
{

	cout << endl;
	cout << setfill('=') << setw(65) << right << "* Sach giao khoa *" << setw(42) << right << "=" << endl;
	cout << endl;
	khungSach();
	cout << setw(12) << left << "Tinh trang " << setw(15) << right << "Thanh tien" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (SachGiaoKhoa* sachGiaoKhoa = dynamic_cast<SachGiaoKhoa*>(mangSach[i]))
		{

			cout << *sachGiaoKhoa << endl;

		}
	}
	cout << setfill('-') << setw(107) << "-" << endl;
	cout << endl;
	cout << "Tong thanh tien sach Giao Khoa: " << (long)(tongSachGiaoKhoa(mangSach)) << endl;
	cout << "\n\n\n";
	cout << setfill('=') << setw(65) << right << "* Sach tham khao *" << setw(42) << right << "=" << endl;
	cout << endl;
	khungSach();
	cout << setw(12) << left << "Thue" << setw(15) << right << "Thanh tien" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < mangSach.size(); i++)
	{
		if (SachThamKhao* sachThamKhao = dynamic_cast<SachThamKhao*>(mangSach[i]))
		{
			cout << *sachThamKhao << endl;
		}
	}
	cout << setfill('-') << setw(107) << "-" << endl;
	cout << endl;
	cout << "Tong thanh tien sach Tham Khao: " << (long)(tongSachThamKhao(mangSach)) << endl;

}
void menu()
{
	cout << "=======================* MENU *============================" << endl;
	cout << "1. Nhap cung                                              *" << endl;
	cout << "2. Nhap mem                                               *" << endl;
	cout << "3. Xuat danh sach                                         *" << endl;
	cout << "4. Xuat danh sach theo ten nha ban cua sach giao khoa     *" << endl;
	cout << "5. Xuat danh sach theo ten nha ban cua sach tham khao     *" << endl;
	cout << "6. Trung binh cong don gia cua sach tham khao             *" << endl;
	cout << "0. Thoat chuong trinh                                     *" << endl;
	cout << "===========================================================" << endl;
}

int main()
{
	vector<Sach*> mangSach;
	int luaChon, chon;
	do
	{
		system("cls");
		menu();
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
			nhapCung(mangSach);
			xuatDanhSach(mangSach);
			break;
		}
		case 2:
		{
			nhapCacLoaiSach(mangSach);
			break;
		}
		case 3:
		{
			xuatDanhSach(mangSach);
			break;
		}
		case 4:
		{
			cin.ignore();
			xuatNXBSachGiaoKhoa(mangSach);
			break;
		}
		case 5:
		{
			cin.ignore();
			xuatNXBSachThamKhao(mangSach);
			break;
		}
		case 6:
		{
			tongDonGiasachThamKhao(mangSach);
			break;
		}
		default:
		{
			luaChon = 0;
		}

		}
		cout << endl;
		cout << "________________________________________________________" << endl;
		cout << "1. Tiep tuc chuong trinh ---- 0. Thoat khoi chuong trinh" << endl;
		cout << "Chon: ";
		cin >> luaChon;

	} while (luaChon != 0);

}
