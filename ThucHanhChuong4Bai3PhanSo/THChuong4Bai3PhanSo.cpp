#include"Fraction1.h"
using namespace std;
void taoPhanSo(Fraction1 mangPhanSo[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		mangPhanSo[i].setNumerator(rand() % n + 1);
		mangPhanSo[i].setDenominator(rand() % n + 1);
	}
}
void xuat(Fraction1 mangPhanSo[])
{
	for (int i = 0; i < 100; i++)
	{
		cout << mangPhanSo[i] << ",";
		if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89)
		{
			cout << endl;
		}
	}
}
void phanSoKhongVuotQua(Fraction1 mangPhanSo[])
{
	Fraction1 phanSo;
	phanSo.setNumerator(1);
	phanSo.setDenominator(2);
	int j = 1;
	for (int i = 0; i < 100; i++)
	{
		if (mangPhanSo[i] <= phanSo)
		{
			cout << mangPhanSo[i] << " ";
		}
	}
}
void phanSoKhongTrungNhau(Fraction1 mangPhanSo[])
{
	int count;
	for (int i = 0; i < 100; i++)
	{
		count = -1;
		for (int j = 0; j < 100; j++)
		{
			if (mangPhanSo[i] == mangPhanSo[j])
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << mangPhanSo[i] << " ";
		}
	}
}
void menu()
{
	cout << "================* MENU *=================" << endl;
	cout << "1. Tao 100 phan so " << endl;
	cout << "2. Thuc hien cac phep tinh " << endl;
	cout << "* Nhap bat so bat ki de thoat *" << endl;
	cout << "=========================================" << endl;
}
void menu1()
{
	cout << "================* MENU *=================" << endl;
	cout << "1. phep cong " << endl;
	cout << "2. phep tru" << endl;
	cout << "3. phep nhan " << endl;
	cout << "4. phep chia" << endl;
	cout << "* Nhap bat so bat ki de thoat *" << endl;
	cout << "=========================================" << endl;
}
int main()
{
	int chon;
	do {
		menu();
		cout << "Nhap lua chon: ";
		cin >> chon;
		switch (chon)
		{

		case 1:
		{
			int luaChon;
			do
			{
				Fraction1 mangPhanSo[1000];
				int n;
				cout << "Nhap gioi han so : ";
				cin >> n;
				taoPhanSo(mangPhanSo, n);
				cout << "Xuat tat ca phan so duoc tao " << endl;
				cout << "-----------------------------------------" << endl;
				xuat(mangPhanSo);
				cout << endl;
				cout << "Xuat cac phan so be hon 1/2" << endl;
				cout << "-----------------------------------------" << endl;
				phanSoKhongVuotQua(mangPhanSo);
				cout << endl;
				cout << "Xuat cac phan so khong trung nhau" << endl;
				cout << "-----------------------------------------" << endl;
				phanSoKhongTrungNhau(mangPhanSo);
				cout << endl;
				cout << "-----------------------------------------" << endl;
				cout << "1. tiep tuc --- 0.Thoat " << endl;
				cout << "Nhap: ";
				cin >> luaChon;
			} while (luaChon != 0);
			break;
		}
		case 2:
		{
			int nhap;
			int luaChon;
			do
			{
				menu1();
				Fraction1 phanSo1, phanSo2, phanSo;
				cout << "Nhap lua chon:";
				cin >> luaChon;
				switch (luaChon)
				{
				case 1:
				{
					cin >> phanSo1;
					cin >> phanSo2;
					phanSo = phanSo1 + phanSo2;
					cout << "ket qua : " << phanSo << endl;
					break;
				}
				case 2:
				{
					cin >> phanSo1;
					cin >> phanSo2;
					phanSo = phanSo1 - phanSo2;
					cout << "Ket qua : " << phanSo << endl;
					break;
				}
				case 3:
				{
					cin >> phanSo1;
					cin >> phanSo2;
					phanSo = phanSo1 * phanSo2;
					cout << "Ket qua : " << phanSo << endl;
					break;
				}
				case 4:
				{
					cin >> phanSo1;
					cin >> phanSo2;
					phanSo = phanSo1 / phanSo2;
					cout << "Ket qua : " << phanSo << endl;
					break;
				}
				default:
				{
					nhap = 0;
				}
				}
				if (chon == 1 || chon == 2 || chon == 3 || chon == 4)
				{
					cout << "1. tiep tuc --- 0.Thoat " << endl;
					cout << "Nhap: ";
					cin >> nhap;
				}
			} while (nhap != 0);
			break;
		}
		default:
		{
			return 0;
		}
		}
		cout << "************************************************************" << endl;
		cout << "1. tiep tuc chuong trinh --- 0.Thoat khoi chuong trinh " << endl;
		cout << "Nhap: ";
		cin >> chon;
	} while (chon != 0);
	return 0;
}
