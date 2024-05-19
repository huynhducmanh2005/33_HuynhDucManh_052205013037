#include "PartTimeEmployee.h"

PartTimeEmployee::PartTimeEmployee()
{
}

PartTimeEmployee::PartTimeEmployee(string maNhanVien, string hoTenNhanVien, string ngayVaoLam, string soDienThoai, int luongCanBan, int soGioLamTrongTuan, int luongMotGio) :Employee(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, luongCanBan)
{
	this->soGioLamTrongTuan = soGioLamTrongTuan;
	this->luongMotGio = luongMotGio;
}




void PartTimeEmployee::setSoGioLamTrongTuan(int soGioLamTrongTuan)
{
	while (true) {
		try {
			if (soGioLamTrongTuan >= 0) {
				throw invalid_argument("So gio lam khong hop le!!");
			}
			this->soGioLamTrongTuan = soGioLamTrongTuan;
			break;
		}
		catch (const invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai : ";
			cin >> soGioLamTrongTuan;

		}
	}
}

void PartTimeEmployee::setLuongMotGio(int luongMotGio)
{
	while (true) {
		try {
			if (luongMotGio >= 0) {
				throw invalid_argument("Luong khong hop le!!");
			}
			this->luongMotGio = luongMotGio;
			break;
		}
		catch (const invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai : ";
			cin >> luongMotGio;

		}
	}
}

int PartTimeEmployee::getSoGioLamTrongTuan() const
{
	return soGioLamTrongTuan;
}

int PartTimeEmployee::getLuongMotGio() const
{
	return luongMotGio;
}

void PartTimeEmployee::inDanhSach() const
{
	Employee::inDanhSach();
	cout << setfill(' ');
	cout << setw(15) << left << soGioLamTrongTuan << setw(15) << left << luongMotGio << (int)tinhLuong() << endl;

}

double PartTimeEmployee::tinhLuong() const
{
	int luongSanPham = soGioLamTrongTuan * luongMotGio;
	int gioLamVuot = soGioLamTrongTuan - 40;
	if (soGioLamTrongTuan > 0 && soGioLamTrongTuan <= 40) {
		return getLuongCanBan() * 0.3 + luongSanPham;
	}
	else if (soGioLamTrongTuan > 40) {
		luongSanPham += gioLamVuot * luongMotGio * 2;
		return getLuongCanBan() * 0.3 + luongSanPham;
	}

}

ostream& operator<<(ostream& out, const PartTimeEmployee& f)
{
	f.inDanhSach();
	return out;

}

