#pragma once
#include "Showroom.h"
#include "OtoKhach.h"
#include "OtoTai.h"
#include <vector>

void khung() {
	cout << setfill(' ');
	cout << setw(8) << left << "Ma" << setw(13) << left << "Nam SX";
	cout << setw(21) << left << "Dung Tich Dong Co" << setw(16) << left << "Tri Gia Xe";

}

void nhapCung(vector<Showroom*>& danhSachXe) {
	danhSachXe.push_back(new OtoKhach("K001", 2003, 300, 30000000000, "xe khac", 20));
	danhSachXe.push_back(new OtoKhach("K002", 2008, 300, 800000000, "xe du lich", 17));
	danhSachXe.push_back(new OtoKhach("K003", 2004, 800, 450000000, "xe ban tai", 2));
	danhSachXe.push_back(new OtoTai("T004", 2007, 300, 300000000, 1000));
	danhSachXe.push_back(new OtoTai("T005", 2005, 400, 350000000, 850));
	cout << endl;
}
void xuatDanhSachXe(vector<Showroom*> danhSachXe) {
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Oto Khach * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(16) << left << "Loai Xe" << setw(12) << left << "So cho" << setw(17) << left << "Thue" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachXe.size(); i++) {
		if (OtoKhach* otokhach = dynamic_cast<OtoKhach*>(danhSachXe[i])) {
			cout << *otokhach << endl;
		}
	}
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Oto Tai * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(15) << left << "Tai trong" << setw(15) << left << "Thue" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachXe.size(); i++) {
		if (OtoTai* ototai = dynamic_cast<OtoTai*>(danhSachXe[i])) {
			cout << *ototai << endl;
		}
	}
}

bool kiemTraMaTrung(const vector<Showroom*>& danhSachXe, const string& ma) {
	for (const auto& xe : danhSachXe) {
		if (xe->getMa() == ma) {
			return true;
		}
	}
	return false;
}

vector<Showroom*> danhSachXe;
void themXe(string& ma, int& namSX, double& dungTichDongCo, int& triGiaXe) {
	cin.ignore();
	cout << "Ma xe: ";
	getline(cin, ma);
	cout << "Nam san xuat: ";
	cin >> namSX;
	cout << "Dung tich dong co: ";
	cin >> dungTichDongCo;
	cout << "Tri gia xe: ";
	cin >> triGiaXe;

}
OtoKhach nhapotokhach(vector<Showroom*>& danhSachXe) {
	OtoKhach otokhach;
	string ma, loaiXe;
	double dungTichDongCo;
	int triGiaXe, namSX, soCho;
	do {
		themXe(ma, namSX, dungTichDongCo, triGiaXe);
		if (kiemTraMaTrung(danhSachXe, ma)) {
			cout << "Ma xe da ton tai. Vui long nhap ma khac." << endl;
		}
	} while (kiemTraMaTrung(danhSachXe, ma));
	cin.ignore();
	cout << "Loai xe:";
	getline(cin, loaiXe);
	cout << "So cho: ";
	cin >> soCho;
	otokhach.setMa(ma);
	otokhach.setNamSX(namSX);
	otokhach.setDungTichDongCo(dungTichDongCo);
	otokhach.setTriGiaXe(triGiaXe);
	otokhach.setLoaiXe(loaiXe);
	otokhach.setSoCho(soCho);
	return otokhach;
}
OtoTai nhapototai(vector<Showroom*>& danhSachXe) {
	string ma;
	double dungTichDongCo;
	int triGiaXe, namSX;
	float taiTrong;
	do {
		themXe(ma, namSX, dungTichDongCo, triGiaXe);
		if (kiemTraMaTrung(danhSachXe, ma)) {
			cout << "Ma xe da ton tai. Vui long nhap ma khac." << endl;
		}
	} while (kiemTraMaTrung(danhSachXe, ma));
	cout << "Tai trong: ";
	cin >> taiTrong;
	return OtoTai(ma, namSX, dungTichDongCo, triGiaXe, taiTrong);
}
void nhapThemXe(vector<Showroom*>& danhSachXe) {
	int luaChon = 1;
	while (luaChon != 0) {
		try {
			do {
				int chon;
				cout << "--------------------------------" << endl;
				cout << "1. Them xe oto khach" << endl;
				cout << "2. Them xe oto tai" << endl;
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
					cout << "THEM XE OTO KHACH" << endl;
					cout << "-------------------" << endl;
					do
					{
						danhSachXe.push_back(new OtoKhach(nhapotokhach(danhSachXe)));
						cout << endl;
						cout << "1. Tiep tuc them oto khach  --- 0. Thoat" << endl;
						cout << "Nhap:";
						cin >> nhap;
					} while (nhap != 0);
					break;
				}
				case 2:
				{
					int nhap;
					cout << "THEM XE OTO TAI" << endl;
					cout << "-------------------" << endl;
					do
					{
						danhSachXe.push_back(new OtoTai(nhapototai(danhSachXe)));
						cout << endl;
						cout << "1. Tiep tuc them oto tai  --- 0. Thoat" << endl;
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
					cout << "1. Tiep tuc them xe" << endl;
					cout << "0. Thoat khoi phan nhap" << endl;
					cout << "Nhap:";
					cin >> luaChon;
				}
			} while (luaChon != 0);
		}
		catch (const exception& e)
		{
			cerr << "Loi: " << e.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
void demSoLuongXe(const vector<Showroom*>& danhSachXe) {
	vector<Showroom*> danhSachXeThoaDieuKien;
	int count = 0;
	cout << "\nDanh sach xe co thue truoc ba > 200.000.000\n";
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Oto Khach * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(16) << left << "Loai Xe" << setw(12) << left << "So cho" << setw(17) << left << "Thue" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachXe.size(); i++) {
		if (OtoKhach* otokhach = dynamic_cast<OtoKhach*>(danhSachXe[i])) {
			if (otokhach->thueTruocBa() > 2000000) {
				danhSachXe[i]->toString();
				count++;
			}
		}
	}
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Oto Tai * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(15) << left << "Tai trong" << setw(15) << left << "Thue" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachXe.size(); i++) {
		if (OtoTai* ototai = dynamic_cast<OtoTai*>(danhSachXe[i])) {
			if (ototai->thueTruocBa() > 200000000) {
				danhSachXe[i]->toString();
				count++;
			}
		}
	}
	cout << endl;
	if (count == 0) {
		cout << endl;
		cout << "\"Khong co xe co thue truoc ba >200.000.000\" " << endl;
	}
	else {
		cout << "Co " << count << " xe co thue truoc ba >200.000.000" << endl;
	}
}
void xuatOtoKhachDuocSXNamx(vector<Showroom*> danhSachXe) {
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Oto Khach * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(16) << left << "Loai Xe" << setw(12) << left << "So cho" << setw(17) << left << "Thue" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;
	for (int i = 0; i < danhSachXe.size(); i++) {
		if (OtoKhach* otokhach = dynamic_cast<OtoKhach*>(danhSachXe[i])) {
			cout << *otokhach << endl;
		}
	}
	int nhap = 0;
	do {
		int namsx;
		int count = 0;
		cout << "\nNhap nam san xuat: ";
		cin >> namsx;
		cout << endl;
		cout << setfill('=') << setw(65) << right << " * Oto Khach * " << setw(42) << right << "=" << endl;
		cout << endl;
		khung();
		cout << setw(16) << left << "Loai Xe" << setw(12) << left << "So cho" << setw(17) << left << "Thue" << endl;
		cout << setfill('-') << setw(107) << "-" << endl;
		for (int i = 0; i < danhSachXe.size(); i++) {
			if (OtoKhach* otokhach = dynamic_cast<OtoKhach*>(danhSachXe[i])) {
				if (otokhach->getNamSX() == namsx) {
					danhSachXe[i]->toString();
					count++;
				}
			}
		}
		cout << endl;
		if (count == 0) {
			cout << "\"Khong co oto khach san xuat trong nam " << namsx << "\"" << endl;
			cout << endl;
		}
		else {
			cout << "\"Co " << count << " xe duoc san xuat trong nam " << namsx << "\"" << endl;
			cout << endl;
		}
		cout << "Ban co muon tiep tuc tim nua khong\n";
		cout << "1. Co  ____ 0. Khong" << endl;
		cin >> nhap;
	} while (nhap == 1);
}

void capNhatGiaTriXe(vector<Showroom*>& danhSachXe) {
	cout << endl;
	cout << "DANH SACH XE TRUOC KHI CAP NHAT GIA" << endl;
	xuatDanhSachXe(danhSachXe);
	string ma;
	cout << endl;
	int count = 0;
	int chon;
	do {
		cout << endl;
		cout << "Nhap ma xe can cap nhat: ";
		cin >> ma;
		count = 0;
		for (int i = 0; i < danhSachXe.size(); i++) {
			if (OtoKhach* otokhach = dynamic_cast<OtoKhach*>(danhSachXe[i])) {
				if (ma == otokhach->getMa()) {
					cout << endl;
					cout << "Cap nhat tri gia xe cho " << otokhach->getMa() << ": ";
					long int giaXe;
					cin >> giaXe;
					otokhach->setTriGiaXe(giaXe);
					khung();
					cout << setw(16) << left << "Loai Xe" << setw(12) << left << "So cho" << setw(17) << left << "Thue" << endl;
					cout << setfill('-') << setw(107) << "-" << endl;
					danhSachXe[i]->toString();
					count++;
				}
			}
		}
		for (int i = 0; i < danhSachXe.size(); i++) {
			if (OtoTai* ototai = dynamic_cast<OtoTai*>(danhSachXe[i])) {
				if (ma == ototai->getMa()) {
					cout << endl;
					cout << "Cap nhat tri gia xe cho " << ototai->getMa() << ": ";
					int giaXe;
					cin >> giaXe;
					ototai->setTriGiaXe(giaXe);
					khung();
					cout << setw(15) << left << "Tai trong" << setw(15) << left << "Thue" << endl;
					cout << setfill('-') << setw(107) << "-" << endl;
					danhSachXe[i]->toString();
					count++;
				}
			}
		}
		if (count == 0) {
			cout << "KHONG CO MA XE NAY.\n";
		}
		cout << "----------------------------------------------------------" << endl;
		cout << "1. Tiep tuc cap nhat   0.Thoat " << endl;
		cout << "Chon:";
		cin >> chon;
	} while (chon == 1);
}
bool soSanhNamSX(const Showroom* s1, const Showroom* s2) {
	return s1->getNamSX() > s2->getNamSX();

}
void sapXepGiamTheoNamSanXuat(vector<Showroom*>& danhSachXe) {
	cout << endl;
	cout << "DANH SACH XE TRUOC KHI SAP XEP";
	xuatDanhSachXe(danhSachXe);
	cout << endl;

	sort(danhSachXe.begin(), danhSachXe.end(), soSanhNamSX);

	cout << "DANH SACH XE SAU KHI SAP XEP GIAM DAN THEO NAM SAN XUAT \n";
	cout << endl;
	for (int i = 0; i < danhSachXe.size(); i++) {
		danhSachXe[i]->toString();
	}
}
void menu() {
	cout << "   DAY LA CHUONG TRINH QUAN LY SHOWROOM XE  \n ";
	cout << endl;
	cout << "--------------------MENU-------------------" << endl;
	cout << "1. Nhap cung va xuat danh sach xe" << endl;
	cout << "2. Them xe vao danh sach " << endl;
	cout << "3. So luong xe co thue truoc ba >200.000.000" << endl;
	cout << "4. Xe oto khach duoc san xuat trong nam x" << endl;
	cout << "5. Cap nhat tri gia xe " << endl;
	cout << "6. Sap xep xe giam dan theo nam san xuat" << endl;
	cout << "0. Thoat chuong trinh                      " << endl;
	cout << "================================================" << endl;

}
int main() {
	vector<Showroom*> danhSachXe;
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
			danhSachXe.clear();
			nhapCung(danhSachXe);
			xuatDanhSachXe(danhSachXe);
			break;
		}
		case 2:
		{
			nhapThemXe(danhSachXe);
			xuatDanhSachXe(danhSachXe);
			break;
		}
		case 3:
		{
			demSoLuongXe(danhSachXe);
			break;

		}
		case 4:
		{
			xuatOtoKhachDuocSXNamx(danhSachXe);
			break;
		}
		case 5:
		{
			capNhatGiaTriXe(danhSachXe);
			break;
		}
		case 6:
		{
			sapXepGiamTheoNamSanXuat(danhSachXe);
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