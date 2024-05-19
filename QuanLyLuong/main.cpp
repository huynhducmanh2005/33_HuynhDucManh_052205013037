#pragma once
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include <vector>
#include <iomanip>
#include <algorithm>

void khung() {
	cout << setfill(' ');
	cout << setw(10) << left << "Ma" << setw(14) << left << "Ho Ten" << setw(15) << left << "Ngay vao lam" << setw(15) << left << "So dien thoai" << setw(14) << left << "Luong can ban";

}
string chuanHoaTen2(string& ten)
{
	ten[0] = toupper(ten[0]);
	for (int i = 1; i < ten.size(); i++)
	{
		ten[i] = tolower(ten[i]);
	}
	return ten;
}
void chuanHoaTen1(string& hoTenNhanVien)
{
	string tenTamThoi; string ten = "";
	vector<string> chuoiTen;
	while (hoTenNhanVien[0] == ' ')
	{
		hoTenNhanVien.erase(hoTenNhanVien.begin() + 0);
	}
	for (int i = 0; i < hoTenNhanVien.size(); i++)
	{
		if (hoTenNhanVien[i] != 0)
		{
			tenTamThoi = "";
			int j = i;
			while (j < hoTenNhanVien.size())
			{
				if (hoTenNhanVien[j] == ' ')
				{
					break;
				}
				else
				{
					tenTamThoi = tenTamThoi + hoTenNhanVien[j];
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
	hoTenNhanVien = ten;
}
bool isValidNgayVaoLam(const std::string& ngayVaoLam) {
	// Kiểm tra độ dài của chuỗi
	if (ngayVaoLam.size() != 10) {
		return false;
	}

	// Kiểm tra các ký tự tại các vị trí cụ thể trong chuỗi
	if (ngayVaoLam[2] != '/' || ngayVaoLam[5] != '/') {
		return false;
	}


	// Kiểm tra các ký tự số trong ngày, tháng, năm
	for (int i = 0; i < ngayVaoLam.size(); i++) {
		if (i != 2 && i != 5 && !isdigit(ngayVaoLam[i])) {
			return false;
		}
	}

	// Lấy thời gian hiện tại
	chrono::system_clock::time_point now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);

	// So sánh ngày với thời gian hiện tại
	tm now_tm;
	localtime_s(&now_tm, &now_time);
	int currentYear = now_tm.tm_year + 1900;
	int currentMonth = now_tm.tm_mon + 1;
	int currentDay = now_tm.tm_mday;

	int year = std::stoi(ngayVaoLam.substr(6, 4));
	int month = std::stoi(ngayVaoLam.substr(3, 2));
	int day = std::stoi(ngayVaoLam.substr(0, 2));

	if (year > currentYear || (year == currentYear && month > currentMonth) || (year == currentYear && month == currentMonth && day > currentDay)) {
		return false;
	}
	// Kiểm tra ngày và tháng hợp lệ
	if (day < 1 || day > 31 || month < 1 || month > 12) {
		return false;
	}
	return true;
}
bool isValidPhoneNumber(const std::string& soDienThoai) {
	// Kiểm tra độ dài của chuỗi Kiểm tra ký tự đầu tiên có phải là số 0
	if (soDienThoai.length() != 10 || soDienThoai[0] != '0') {
		return false;
	}

	// Kiểm tra các ký tự còn lại có phải là số
	for (int i = 1; i < soDienThoai.length(); i++) {
		if (!isdigit(soDienThoai[i])) {
			return false;
		}
	}

	return true;
}

void nhapCung(vector<Employee*>& danhSachNhanVien)
{
	danhSachNhanVien.push_back(new FullTimeEmployee("M001", "Huynh Ngo Yen Di", "12/03/2023", "0367259980", 3000000, 3.0, 2));
	danhSachNhanVien.push_back(new PartTimeEmployee("M002", "Nguyen Thi Thao", "28/02/2024", "0965336908", 2000000, 37, 22000));
	danhSachNhanVien.push_back(new FullTimeEmployee("M003", "Huynh Duc Manh", "10/08/2023", "0362280768", 3000000, 3.0, 3));
	danhSachNhanVien.push_back(new FullTimeEmployee("M004", "Dang Duy Khanh", "22/01/2024", "0369089332", 2800000, 3.0, 1));
	danhSachNhanVien.push_back(new PartTimeEmployee("M005", "Nguyen Thanh Khiem", "18/09/2023", "0965721554", 3000000, 45, 24000));

}
void xuatDanhSachNhanVien(vector<Employee*> danhSachNhanVien)
{
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * FullTimeEmployee * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(13) << right << "He so luong " << setw(15) << left << "So nam kinh nghiem" << setw(15) << left << "Luong" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;

	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (FullTimeEmployee* fullTime = dynamic_cast<FullTimeEmployee*>(danhSachNhanVien[i])) {
			cout << *fullTime << endl;
		}
	}
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * PartTimeEmployee * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(17) << left << "So gio lam/tuan" << setw(17) << left << "Luong mot gio" << setw(15) << left << "Luong" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (PartTimeEmployee* partTime = dynamic_cast<PartTimeEmployee*>(danhSachNhanVien[i])) {
			cout << *partTime << endl;
		}
	}
}
vector<Employee*> danhSachNhanVien;
void themNhanVien(string& maNhanVien, string& hoTenNhanVien, string& ngayVaoLam, string& soDienThoai, int& luongCanBan) {
	cin.ignore();
	bool trungMa = false;

	do {
		cout << "Ma nhan vien: ";
		getline(cin, maNhanVien);
		trungMa = false;
		for (int i = 0; i < danhSachNhanVien.size(); i++) {
			if (danhSachNhanVien[i]->getMaNhanVien() == maNhanVien) {
				cout << "Ma nhan vien da ton tai. Vui long nhap lai." << endl;
				trungMa = true;
				break;
			}
		}
	} while (trungMa);
	cout << "Ho ten nhan vien: ";
	getline(cin, hoTenNhanVien);
	do {
		cout << "Ngay vao lam(dd/mm/yy): ";
		getline(cin, ngayVaoLam);
		if (!isValidNgayVaoLam(ngayVaoLam)) {
			cout << "Ngay vao lam khong hop le hoac lon hon ngay hien tai! Vui long nhap lai!" << endl;

		}
	} while (!isValidNgayVaoLam(ngayVaoLam));
	chuanHoaTen1(hoTenNhanVien);
	cout << "So dien thoai: ";
	getline(cin, soDienThoai);
	cout << "Luong can ban: ";
	cin >> luongCanBan;


}
FullTimeEmployee nhapFullTime() {
	FullTimeEmployee nvfulltime;
	string maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai;
	int luongCanBan, heSoLuong, soNamKinhNghiem;
	themNhanVien(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, luongCanBan);
	cout << "He so luong: ";
	cin >> heSoLuong;

	cout << "So nam kinh nghiem: ";
	cin >> soNamKinhNghiem;
	nvfulltime.setMaNhanVien(maNhanVien);
	nvfulltime.setHoTenNhanVien(hoTenNhanVien);
	nvfulltime.setNgayVaoLam(ngayVaoLam);
	nvfulltime.setSoDienThoai(soDienThoai);
	nvfulltime.setLuongCanBan(luongCanBan);
	nvfulltime.setHeSoLuong(heSoLuong);
	nvfulltime.setSoNamKinhNghiem(soNamKinhNghiem);
	return nvfulltime;

}
PartTimeEmployee nhapParttime() {
	string maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai;
	int luongCanBan, soGioLamTrongTuan, luongMotGio;
	themNhanVien(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, luongCanBan);
	cout << "So gio lam/tuan: ";
	cin >> soGioLamTrongTuan;
	cout << "Luong mot gio: ";
	cin >> luongMotGio;
	return PartTimeEmployee(maNhanVien, hoTenNhanVien, ngayVaoLam, soDienThoai, luongCanBan, soGioLamTrongTuan, luongMotGio);

}
void nhapThemNhanVien(vector<Employee*>& danhSachNhanVien) {
	int luaChon;
	do {
		int chon;
		cout << "--------------------------------" << endl;
		cout << "1. Them nhan vien FullTime" << endl;
		cout << "2. Them nhan vien PartTime" << endl;
		cout << "0. Thoat khoi phan nhap " << endl;
		cout << "--------------------------------" << endl;
		cout << "Nhap: ";
		cin >> chon;
		switch (chon) {
		case 0:
		{
			luaChon = 0;
			break;
		}
		case 1:
		{
			int nhap;
			cout << "THEM NHAN VIEN FULLTIME" << endl;
			cout << "-------------------" << endl;
			do
			{
				danhSachNhanVien.push_back(new FullTimeEmployee(nhapFullTime()));
				cout << endl;
				cout << "1. Tiep tuc nhap  --- 0. Thoat" << endl;
				cout << "Nhap:";
				cin >> nhap;
			} while (nhap != 0);
			break;
		}
		case 2:
		{
			int nhap;
			cout << "THEM NHAN VIEN PARTTIME" << endl;
			cout << "-------------------" << endl;
			do
			{
				danhSachNhanVien.push_back(new PartTimeEmployee(nhapParttime()));
				cout << endl;
				cout << "1. Tiep tuc nhap  --- 0. Thoat" << endl;
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
			cout << "1. Tiep tuc them nhan vien" << endl;
			cout << "0. Thoat khoi phan nhap" << endl;
			cout << "Nhap:";
			cin >> luaChon;
		}
	} while (luaChon != 0);
}
void tongLuongFullTimeEmployee(vector<Employee*> danhSachNhanVien) {
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * FullTimeEmployee * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(13) << right << "He so luong " << setw(15) << left << "So nam kinh nghiem" << setw(15) << left << "Luong" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;

	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (FullTimeEmployee* fullTime = dynamic_cast<FullTimeEmployee*>(danhSachNhanVien[i])) {
			cout << *fullTime << endl;
		}
	}
	int sum = 0;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (FullTimeEmployee* fullTime = dynamic_cast<FullTimeEmployee*>(danhSachNhanVien[i])) {
			sum = sum + danhSachNhanVien[i]->tinhLuong();
		}
	}
	cout << endl;
	cout << "TONG LUONG NHAN VIEN FULLTIME: " << setw(72) << right << sum << endl;
}
void tongLuongPartTimeEmployee(vector<Employee*> danhSachNhanVien) {
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * PartTimeEmployee * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(17) << left << "So gio lam/tuan" << setw(18) << left << "Luong mot gio" << setw(15) << left << "Luong" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (PartTimeEmployee* partTime = dynamic_cast<PartTimeEmployee*>(danhSachNhanVien[i])) {
			cout << *partTime << endl;
		}
	}
	int sum = 0;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (PartTimeEmployee* partTime = dynamic_cast<PartTimeEmployee*>(danhSachNhanVien[i])) {
			sum = sum + danhSachNhanVien[i]->tinhLuong();
		}
	}
	cout << endl;
	cout << "TONG LUONG NHAN VIEN PARTTIME: " << setw(75) << right << sum << endl;

}
void tinhTongLuong(vector<Employee*> danhSachNhanVien) {
	int tongLuong = 0;
	for (const auto& nv : danhSachNhanVien) {
		tongLuong += nv->tinhLuong();
	}
	cout << endl;
	cout << "TONG LUONG TOAN BO NHAN VIEN: " << setw(75) << right << tongLuong << endl;

}
void tinhLuongNhanVien(vector<Employee*> danhSachNhanVien) {
	int luaChon;
	do {
		system("cls");
		int chon;
		cout << "--------------------------------" << endl;
		cout << "1. Tinh tong luong nhan vien fulltime" << endl;
		cout << "2. Tinh tong luong nhan vien parttime" << endl;
		cout << "3. Tinh tong luong toan bo nhan vien" << endl;
		cout << "0. Thoat khoi phan nhap        |" << endl;
		cout << "--------------------------------" << endl;
		cout << "Nhap: ";
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
			tongLuongFullTimeEmployee(danhSachNhanVien);
			break;
		}
		case 2:
		{
			tongLuongPartTimeEmployee(danhSachNhanVien);
			break;
		}
		case 3:
		{
			xuatDanhSachNhanVien(danhSachNhanVien);
			tinhTongLuong(danhSachNhanVien);
			break;
		}
		default:
		{
			luaChon = 0;
		}
		}
		cout << "----------------------------------------------------------" << endl;
		cout << "1. Tiep tuc chuong trinh   0.Thoat khoi chuong trinh" << endl;
		cout << "Chon:";
		cin >> luaChon;
	} while (luaChon != 0);
}
void demNhanVienVaoLamTrongNam(const vector<Employee*>& danhSachNhanVien) {
	vector<Employee*> nhanVienTrongNam;
	int count = 0;
	int nam;
	cout << "Nhap nam: ";
	cin >> nam;
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * FullTimeEmployee * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(13) << right << "He so luong " << setw(15) << left << "So nam kinh nghiem" << setw(15) << left << "Luong" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (FullTimeEmployee* fullTime = dynamic_cast<FullTimeEmployee*>(danhSachNhanVien[i])) {
			int namVaoLam = stoi(fullTime->getNgayVaoLam().substr(6, 4));
			if (namVaoLam == nam) {
				danhSachNhanVien[i]->inDanhSach();
				count++;
			}

		}
	}
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * PartTimeEmployee * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(17) << left << "So gio lam/tuan" << setw(17) << left << "Luong mot gio" << setw(15) << left << "Luong" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (PartTimeEmployee* partTime = dynamic_cast<PartTimeEmployee*>(danhSachNhanVien[i])) {
			int namVaoLam = stoi(partTime->getNgayVaoLam().substr(6, 4));
			if (namVaoLam == nam) {
				danhSachNhanVien[i]->inDanhSach();
				count++;
			}

		}

	}
	cout << endl;
	if (count == 0) {
		cout << "Khong co nhan vien lam trong nam " << nam << endl;
	}
	else {
		cout << "Co " << count << " nhan vien vao lam trong nam " << nam << endl;
	}

}
void capNhatGioLamChoNhanVien(vector<Employee*>& danhSachNhanVien) {
	cout << "Danh sach nhan vien parttime truoc khi cap nhat!" << endl;
	cout << endl;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (PartTimeEmployee* partTime = dynamic_cast<PartTimeEmployee*>(danhSachNhanVien[i])) {
			danhSachNhanVien[i]->inDanhSach();

		}
	}
	string ma;
	cout << endl;
	cout << "Nhap ma nhan vien can cap nhat: ";
	cin >> ma;

	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		if (PartTimeEmployee* partTime = dynamic_cast<PartTimeEmployee*>(danhSachNhanVien[i])) {
			if (ma == partTime->getMaNhanVien()) {
				cout << endl;
				cout << "Cap nhat so gio lam cho " << partTime->getMaNhanVien() << ": ";
				int soGioLam;
				cin >> soGioLam;
				partTime->setSoGioLamTrongTuan(soGioLam);
				danhSachNhanVien[i]->inDanhSach();
			}

		}
	}
}
bool soSanhNgayVao(const Employee* empl1, const Employee* empl2) {
	return empl1->getNgayVaoLam() > empl2->getNgayVaoLam();
}
void sapXepNgayVao(vector<Employee*>& danhSachNhanVien) {
	cout << endl;
	cout << "Xuat danh sach nhan vien truoc khi sap xep: \n";
	cout << endl;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		danhSachNhanVien[i]->inDanhSach();
	}

	sort(danhSachNhanVien.begin(), danhSachNhanVien.end(), soSanhNgayVao);
	cout << endl;
	cout << "Danh sach nhan vien sau khi sap xep giam dan theo ngay vao lam:\n ";
	cout << endl;
	for (int i = 0; i < danhSachNhanVien.size(); i++) {
		danhSachNhanVien[i]->inDanhSach();
	}


}
void xoaNhanVien(vector<Employee*>& danhSachNhanVien) {
	string ma;
	int chon;
	cout << "Nhap ma nhan vien can xoa: ";
	cin.ignore();
	getline(cin, ma);
	auto it = find_if(danhSachNhanVien.begin(), danhSachNhanVien.end(), [ma](const Employee* employee) {
		return employee->getMaNhanVien() == ma;
		});
	if (it != danhSachNhanVien.end()) {
		cout << "Ban chac chan muon xoa khong!!" << endl;
		cout << "Xoa thi nhap phim 1!!" << endl;
		cout << "Chon: ";
		cin >> chon;
		if (chon == 1) {
			delete* it;
			danhSachNhanVien.erase(it);
			cout << "Da xoa nhan vien co ma " << ma << endl;
		}
		else {
			cout << "Khong muon xoa!!" << endl;
		}
	}
	else {
		cout << "Khong tim thay ma nhan vien can xoa!!" << endl;
	}
}
void menu() {
	cout << "------------MENU-----------" << endl;
	cout << "1. Nhap cung va xuat danh sach nhan vien" << endl;
	cout << "2. Them nhan vien vao danh sach " << endl;
	cout << "3. Tinh luong cho nhan vien " << endl;
	cout << "4. Dem so luong nhan vien trong nam bat ki" << endl;
	cout << "5. Cap nhat so gio lam cho nhan vien " << endl;
	cout << "6. Sap xep nhan vien giam dan theo ngay vao lam" << endl;
	cout << "7. Xoa nhan vien khoi danh sach" << endl;
	cout << "0. Thoat chuong trinh                      " << endl;
	cout << "===============================================" << endl;

}
int main() {
	vector<Employee*> danhSachNhanVien;
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
			danhSachNhanVien.clear();
			nhapCung(danhSachNhanVien);
			xuatDanhSachNhanVien(danhSachNhanVien);
			break;
		}
		case 2:
		{
			nhapThemNhanVien(danhSachNhanVien);
			xuatDanhSachNhanVien(danhSachNhanVien);
			break;
		}
		case 3:
		{
			tinhLuongNhanVien(danhSachNhanVien);
			break;
		}
		case 4:
		{
			cout << "SO LUONG NHAN VIEN TRONG NAM BAT KI\n";
			cout << endl;
			demNhanVienVaoLamTrongNam(danhSachNhanVien);
			break;
		}
		case 5:
		{
			cout << "CAP NHAT GIO LAM CHO NHAN VIEN " << endl;
			try {
				capNhatGioLamChoNhanVien(danhSachNhanVien);
			}
			catch (const runtime_error& error) {
				cerr << "Loi: " << error.what() << endl;
			}
			break;
		}
		case 6:
		{
			cout << "SAP XEP NHAN VIEN GIAM DAN THEO NGAY VAO" << endl;
			sapXepNgayVao(danhSachNhanVien);
			break;
		}
		case 7:
		{
			cout << "XOA NHAN VIEN\n";
			cout << endl;
			xoaNhanVien(danhSachNhanVien);
			break;
		}
		default:
		{
			luaChon = 0;
		}

		}
		cout << endl;
		cout << "________________________________________________________" << endl;
		cout << "1. Tiep tuc chuong trinh chinh ---- 0. Thoat khoi chuong trinh chinh" << endl;
		cout << "Chon: ";
		cin >> luaChon;

	} while (luaChon != 0);




}




