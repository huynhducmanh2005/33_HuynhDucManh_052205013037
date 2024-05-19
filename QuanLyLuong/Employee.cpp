#include "Employee.h"

Employee::Employee()
{
}

Employee::Employee(string maNhanVien, string hoTenNhanVien, string ngayVaoLam, string soDienThoai, int luongCanBan)
{
	this->maNhanVien = maNhanVien;
	this->hoTenNhanVien = hoTenNhanVien;
	this->ngayVaoLam = ngayVaoLam;
	this->soDienThoai = soDienThoai;
	this->luongCanBan = luongCanBan;
}

void Employee::setMaNhanVien(string maNhanVien)
{
	while (true) {
		try {
			if (maNhanVien.empty()) {
				throw invalid_argument("Ma nhan vien khong duoc rong!");
			}

			if (maNhanVien.length() != 4 || !isalpha(maNhanVien[0]) || !isdigit(maNhanVien[1]) ||
				!isdigit(maNhanVien[2]) || !isdigit(maNhanVien[3])) {
				throw invalid_argument("Ma nhan vien khong hop le!");
			}

			this->maNhanVien = maNhanVien;
			break; // Thoát khỏi vòng lặp khi dữ liệu hợp lệ
		}
		catch (const invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai ma nhan vien: ";
			getline(cin, maNhanVien);
		}
	}

}

void Employee::setHoTenNhanVien(string hoTenNhanVien)
{
	while (true) {
		try {

			for (char c : hoTenNhanVien) {
				if (isdigit(c)) {
					throw std::invalid_argument("Ho ten nhan vien chi duoc chua chu cai!");
				}
			}

			this->hoTenNhanVien = hoTenNhanVien;
			break; // Thoát khỏi vòng lặp khi dữ liệu hợp lệ
		}
		catch (const std::invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai ho ten nhan vien: ";
			getline(cin, hoTenNhanVien);
		}
	}
}

void Employee::setNgayVaoLam(string ngayVaoLam)
{
	this->ngayVaoLam = ngayVaoLam;
}

void Employee::setSoDienThoai(string soDienThoai)
{
	while (true) {
		try {
			// Kiểm tra độ dài Kiểm tra ký tự đầu tiên
			if (soDienThoai[0] != '0') {
				throw invalid_argument("So dien thoai bat dau bang 0!");
			}
			if (soDienThoai.length() != 10) {

				throw invalid_argument("So dien thoai phai gom 10 so!");
			}

			this->soDienThoai = soDienThoai;
			break; // Thoát khỏi vòng lặp khi dữ liệu hợp lệ
		}
		catch (const invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai so dien thoai: ";
			getline(cin, soDienThoai);
		}
	}
}

void Employee::setLuongCanBan(int luongCanBan)
{
	while (true) {
		try {
			if (luongCanBan < 0) {
				throw invalid_argument("Luong can ban khong hop le!!");
			}

			this->luongCanBan = luongCanBan;
			break;
		}
		catch (const invalid_argument& ex) {
			cout << "Loi: " << ex.what() << endl;
			cout << "Vui long nhap lai : ";
			cin >> luongCanBan;

		}
	}
}

string Employee::getMaNhanVien() const
{
	return this->maNhanVien;
}

string Employee::getHoTenNhanVien() const
{
	return this->hoTenNhanVien;
}

string Employee::getNgayVaoLam() const
{
	return this->ngayVaoLam;
}

string Employee::getSoDienThoai() const
{
	return this->soDienThoai;
}

double Employee::getLuongCanBan() const
{
	return this->luongCanBan;
}

void Employee::inDanhSach() const
{
	cout << setfill(' ');
	cout << setw(6) << left << maNhanVien << setw(19) << left << hoTenNhanVien;
	cout << setw(15) << left << ngayVaoLam << setw(15) << left << soDienThoai;
	cout << setw(15) << left << luongCanBan;

}

ostream& operator<<(ostream& out, const Employee& f)
{
	f.inDanhSach();
	return out;
}

