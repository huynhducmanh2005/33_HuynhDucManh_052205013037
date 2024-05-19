#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee()
{
}

FullTimeEmployee::FullTimeEmployee(string maNhanVien, string hoTenNhanVien, string ngayVaoLam, string soDienThoai, int luongCanBan, double heSoLuong, int soNamKinhNghiem) :Employee(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, luongCanBan)
{
	this->heSoLuong = heSoLuong;
	this->soNamKinhNghiem = soNamKinhNghiem;
}

void FullTimeEmployee::setHeSoLuong(double heSoLuong)
{
	while (true) {
		try {
			if (heSoLuong < 1.65) {
				throw invalid_argument("He so luong phai >=1.65!!");
			}
			if (heSoLuong >= 8) {
				throw invalid_argument("He so luong phai <8!!");
			}
			this->heSoLuong = heSoLuong;
			break;
		}
		catch (const invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai : ";
			cin >> heSoLuong;

		}
	}

}

void FullTimeEmployee::setSoNamKinhNghiem(int soNamKinhNghiem)
{
	while (true) {
		try {
			if (soNamKinhNghiem < 0) {
				throw invalid_argument("Nam kinh nghiem khong hop le!!");
			}
			this->soNamKinhNghiem = soNamKinhNghiem;
			break;
		}
		catch (const invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai : ";
			cin >> soNamKinhNghiem;

		}
	}
}

int FullTimeEmployee::getHeSoLuong() const
{
	return this->heSoLuong;
}

int FullTimeEmployee::getSoNamKinhNghiem() const
{
	return this->soNamKinhNghiem;
}

void FullTimeEmployee::inDanhSach() const
{
	Employee::inDanhSach();
	cout << setfill(' ');
	cout << setw(12) << left << heSoLuong << setw(15) << left << soNamKinhNghiem << (int)tinhLuong() << endl;

}

double FullTimeEmployee::tinhLuong() const
{
	int luongTheoHeSo = getLuongCanBan() * heSoLuong;
	int phanTramNamKinhNghiem = soNamKinhNghiem * 0.01;
	return luongTheoHeSo + (phanTramNamKinhNghiem * luongTheoHeSo);
}

ostream& operator<<(ostream& out, const FullTimeEmployee& f)
{
	f.inDanhSach();
	return out;

}

