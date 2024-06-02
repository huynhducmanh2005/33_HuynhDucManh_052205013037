#pragma
#include "PhongHoc.h"
#include "PhongLiThuyet.h"
#include "PhongMayTinh.h"
#include "PhongThiNghiem.h"

void khung() {
	cout << setfill(' ');
	cout << setw(13) << left << "Ma phong" << setw(13) << left << "Day nha";
	cout << setw(14) << left << "Dien tich" << setw(14) << left << "Bong den";
}
void nhapCung(vector<PhongHoc*>& danhSachPhong) {
	danhSachPhong.push_back(new PhongLiThuyet("LT001", "C", 32, 4, 1));
	danhSachPhong.push_back(new PhongMayTinh("MT003", "N", 48, 3, 20));
	danhSachPhong.push_back(new PhongThiNghiem("TN005", "A", 50, 8, "Sinh hoc", 100, 1));
	danhSachPhong.push_back(new PhongLiThuyet("LT003", "D", 52, 4, 0));
	danhSachPhong.push_back(new PhongMayTinh("MT001", "D", 52, 7, 38));
	danhSachPhong.push_back(new PhongThiNghiem("TN004", "B", 36, 2, "Hoa hoc", 50, 0));

}
void khungLiThuyet() {
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Phong Li Thuyet * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(15) << left << "May chieu" << setw(13) << left << "Dat chuan" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;

}
void khungMayTinh() {
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Phong May Tinh * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(15) << left << "May tinh" << setw(13) << left << "Dat chuan" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;

}
void khungThiNghiem() {
	cout << endl;
	cout << setfill('=') << setw(65) << right << " * Phong Thi Nghiem * " << setw(42) << right << "=" << endl;
	cout << endl;
	khung();
	cout << setw(16) << left << "Chuyen nganh" << setw(13) << left << "Suc chua" << setw(13) << left << "Bon rua" << setw(10) << left << "Dat chuan" << endl;
	cout << setfill('-') << setw(107) << "-" << endl;

}
void xuatDanhSach(vector<PhongHoc*> danhSachPhong) {
	khungLiThuyet();

	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongLiThuyet* lt = dynamic_cast<PhongLiThuyet*>(danhSachPhong[i])) {
			cout << *lt << endl;
		}
	}
	khungMayTinh();

	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongMayTinh* mt = dynamic_cast<PhongMayTinh*>(danhSachPhong[i])) {
			cout << *mt << endl;
		}
	}

	khungThiNghiem();

	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongThiNghiem* tn = dynamic_cast<PhongThiNghiem*>(danhSachPhong[i])) {
			cout << *tn << endl;
		}
	}

}
bool kiemTraMaTrung(const vector<PhongHoc*>& danhSachPhong, const string& maPhong) {
	for (const auto& phong : danhSachPhong) {
		if (phong->getMaPhong() == maPhong) {
			return true;
		}
	}
	return false;
}
vector<PhongHoc*> danhSachPhong;
void themPhong(string& maPhong, string& dayNha, float& dienTich, int& bongDen) {
	cin.ignore();
	cout << "Ma phong: ";
	getline(cin, maPhong);
	cout << "Day nha: ";
	getline(cin, dayNha);
	cout << "Dien tich: ";
	cin >> dienTich;
	cout << "So luong bong den: ";
	cin >> bongDen;
}
PhongLiThuyet themPhongLiThuyet(vector<PhongHoc*>& danhSachPhong) {
	string maPhong, dayNha;
	int bongDen, mayChieu;
	float dienTich;
	do {
		themPhong(maPhong, dayNha, dienTich, bongDen);
		if (kiemTraMaTrung(danhSachPhong, maPhong)) {
			cout << "Ma phong da ton tai. Vui long nhap ma khac." << endl;
		}
	} while (kiemTraMaTrung(danhSachPhong, maPhong));
	cout << "May chieu: ";
	cin >> mayChieu;
	return PhongLiThuyet(maPhong, dayNha, dienTich, bongDen, mayChieu);
}
PhongMayTinh themPhongMayTinh(vector<PhongHoc*>& danhSachPhong) {
	string maPhong, dayNha;
	int bongDen, mayTinh;
	float dienTich;
	do {
		themPhong(maPhong, dayNha, dienTich, bongDen);
		if (kiemTraMaTrung(danhSachPhong, maPhong)) {
			cout << "Ma phong da ton tai. Vui long nhap ma khac." << endl;
		}
	} while (kiemTraMaTrung(danhSachPhong, maPhong));
	cout << "May tinh: ";
	cin >> mayTinh;
	return PhongMayTinh(maPhong, dayNha, dienTich, bongDen, mayTinh);
}
PhongThiNghiem themPhongThiNghiem(vector<PhongHoc*>& danhSachPhong) {
	string maPhong, dayNha, chuyenNganh;
	int bongDen, sucChua, bonRua;
	float dienTich;
	do {
		themPhong(maPhong, dayNha, dienTich, bongDen);
		if (kiemTraMaTrung(danhSachPhong, maPhong)) {
			cout << "Ma phong da ton tai. Vui long nhap ma khac." << endl;
		}
	} while (kiemTraMaTrung(danhSachPhong, maPhong));
	cin.ignore();
	cout << "Chuyen nganh: ";
	getline(cin, chuyenNganh);
	cout << "Suc chua: ";
	cin >> sucChua;
	cout << "Bon rua: ";
	cin >> bonRua;
	return PhongThiNghiem(maPhong, dayNha, dienTich, bongDen, chuyenNganh, sucChua, bonRua);
}
void nhapThemPhong(vector<PhongHoc*>& danhSachPhong) {
	int luaChon = 1;
	while (luaChon != 0) {
		try {
			do {
				int chon;
				cout << "--------------------------------" << endl;
				cout << "1. Them phong li thuyet" << endl;
				cout << "2. Them phong may tinh" << endl;
				cout << "3. Them phong thi nghiem" << endl;
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
					do {
						danhSachPhong.push_back(new PhongLiThuyet(themPhongLiThuyet(danhSachPhong)));
						cout << endl;
						cout << "1. Tiep tuc them phong li thuyet  --- 0. Thoat" << endl;
						cout << "Nhap:";
						cin >> nhap;
					} while (nhap != 0);
					break;
				}
				case 2:
				{
					int nhap;
					do {
						danhSachPhong.push_back(new PhongMayTinh(themPhongMayTinh(danhSachPhong)));
						cout << endl;
						cout << "1. Tiep tuc them phong may tinh  --- 0. Thoat" << endl;
						cout << "Nhap:";
						cin >> nhap;
					} while (nhap != 0);
					break;
				}
				case 3:
				{
					int nhap;
					do {
						danhSachPhong.push_back(new PhongThiNghiem(themPhongThiNghiem(danhSachPhong)));
						cout << endl;
						cout << "1. Tiep tuc them phong mthi nghiem  --- 0. Thoat" << endl;
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
				if (chon == 1 || chon == 2 || chon == 3)
				{
					cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
					cout << "1. Tiep tuc them phong" << endl;
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
void timKiemPhongHoc(vector<PhongHoc*> danhSachPhong) {
	xuatDanhSach(danhSachPhong);
	cout << endl;
	int nhap = 0;
	do {
		string maPhongCanTim;
		int count = 0;
		cin.ignore();
		cout << "Nhap ma phong can tim: ";
		getline(cin, maPhongCanTim);

		for (int i = 0; i < danhSachPhong.size(); i++) {
			if (PhongLiThuyet* lt = dynamic_cast<PhongLiThuyet*>(danhSachPhong[i])) {
				if (lt->getMaPhong() == maPhongCanTim) {
					khungLiThuyet();
					danhSachPhong[i]->danhSach();
					count++;
				}
			}
		}

		for (int i = 0; i < danhSachPhong.size(); i++) {
			if (PhongMayTinh* mt = dynamic_cast<PhongMayTinh*>(danhSachPhong[i])) {
				if (mt->getMaPhong() == maPhongCanTim) {
					khungMayTinh();
					danhSachPhong[i]->danhSach();
					count++;
				}
			}
		}


		for (int i = 0; i < danhSachPhong.size(); i++) {
			if (PhongThiNghiem* tn = dynamic_cast<PhongThiNghiem*>(danhSachPhong[i])) {
				if (tn->getMaPhong() == maPhongCanTim) {
					khungThiNghiem();
					danhSachPhong[i]->danhSach();
					count++;
				}
			}
		}
		cout << endl;
		if (count == 0) {
			cout << "Khong co ma nay" << endl;
			cout << endl;
		}

		cout << "Ban co muon tiep tuc tim nua khong\n";
		cout << "1. Co  ____ 0. Khong" << endl;
		cin >> nhap;
	} while (nhap == 1);

}
void layPhongHocDatChuan(vector<PhongHoc*> danhSachPhong) {
	int nhap = 0;
	int count = 0;
	cin.ignore();

	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongLiThuyet* lt = dynamic_cast<PhongLiThuyet*>(danhSachPhong[i])) {
			if (lt->datChuan() == true) {
				khungLiThuyet();
				danhSachPhong[i]->danhSach();
				count++;
			}
		}
	}

	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongMayTinh* mt = dynamic_cast<PhongMayTinh*>(danhSachPhong[i])) {
			if (mt->datChuan() == true) {
				khungMayTinh();
				danhSachPhong[i]->danhSach();
				count++;
			}
		}
	}


	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongThiNghiem* tn = dynamic_cast<PhongThiNghiem*>(danhSachPhong[i])) {
			if (tn->datChuan() == true) {
				khungThiNghiem();
				danhSachPhong[i]->danhSach();
				count++;
			}
		}
	}
	cout << endl;
	if (count == 0) {
		cout << "Khong co phong hoc dat chuan" << endl;
		cout << endl;
	}
	else {
		cout << "Co " << count << " phong hoc dat chuan." << endl;
	}

}

bool soSanhDayNha(const PhongHoc* p1, const PhongHoc* p2) {
	return p1->getDayNha() < p2->getDayNha();

}
void sapXepTangDanTheoDayNha(vector<PhongHoc*>& danhSachPhong) {
	cout << endl;
	cout << "Danh sach phong hoc truoc khi sap xep" << endl;
	xuatDanhSach(danhSachPhong);
	cout << endl;
	sort(danhSachPhong.begin(), danhSachPhong.end(), soSanhDayNha);
	cout << "Danh sach phong sau khi sap xep tang dan theo day nha\n";
	cout << endl;
	for (int i = 0; i < danhSachPhong.size(); i++) {
		danhSachPhong[i]->danhSach();
	}
}
bool soSanhDienTich(const PhongHoc* p1, const PhongHoc* p2) {
	return p1->getDienTich() > p2->getDienTich();
}
void sapXepGiamDanTheoDienTich(vector<PhongHoc*>& danhSachPhong) {
	cout << endl;
	cout << "Danh sach phong hoc truoc khi sap xep" << endl;
	xuatDanhSach(danhSachPhong);
	cout << endl;
	sort(danhSachPhong.begin(), danhSachPhong.end(), soSanhDienTich);
	cout << "Danh sach phong sau khi sap xep giam dan theo dien tich\n";
	cout << endl;
	for (int i = 0; i < danhSachPhong.size(); i++) {
		danhSachPhong[i]->danhSach();
	}
}
bool soSanhBongDen(const PhongHoc* p1, const PhongHoc* p2) {
	return p1->getBongDen() < p2->getBongDen();
}
void sapXepTangDanTheoSoBongDen(vector<PhongHoc*>& danhSachPhong) {
	cout << endl;
	cout << "Danh sach phong hoc truoc khi sap xep" << endl;
	xuatDanhSach(danhSachPhong);
	cout << endl;
	sort(danhSachPhong.begin(), danhSachPhong.end(), soSanhBongDen);
	cout << "Danh sach phong sau khi sap xep tang dan theo so bong den\n";
	cout << endl;
	for (int i = 0; i < danhSachPhong.size(); i++) {
		danhSachPhong[i]->danhSach();
	}
}
void capNhatSoMayTinh(vector<PhongHoc*>& danhSachPhong) {
	cout << endl;
	cout << "Phong may tinh truoc khi cap nhat\n" << endl;
	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongMayTinh* mt = dynamic_cast<PhongMayTinh*>(danhSachPhong[i])) {
			khungMayTinh();
			mt->danhSach();
		}
	}
	string ma;
	cout << endl;
	int count = 0;
	int chon;
	do {
		cout << endl;
		cout << "Nhap ma phong can cap nhat: ";
		cin >> ma;
		count = 0;
		for (int i = 0; i < danhSachPhong.size(); i++) {
			if (PhongMayTinh* mt = dynamic_cast<PhongMayTinh*>(danhSachPhong[i])) {
				if (ma == mt->getMaPhong()) {
					cout << endl;
					cout << "Cap nhat so may tinh cho phong " << mt->getMaPhong() << ": ";
					int soMayTinh;
					cin >> soMayTinh;
					mt->setMayTinh(soMayTinh);
					khungMayTinh();
					danhSachPhong[i]->danhSach();
					count++;
				}
			}
		}if (count == 0) {
			cout << "KHONG CO MA PHONG NAY.\n";
		}
		cout << "----------------------------------------------------------" << endl;
		cout << "1. Tiep tuc cap nhat   0.Thoat " << endl;
		cout << "Chon:";
		cin >> chon;
	} while (chon == 1);

}
void xoaPhongHoc(vector<PhongHoc*>& danhSachPhong) {
	string ma;
	int chon;
	cout << "Nhap ma phong can xoa: ";
	cin.ignore();
	getline(cin, ma);
	auto it = find_if(danhSachPhong.begin(), danhSachPhong.end(), [ma](const PhongHoc* ph) {
		return ph->getMaPhong() == ma;
		});
	if (it != danhSachPhong.end()) {
		cout << "Ban chac chan muon xoa khong!!" << endl;
		cout << "Xoa thi nhap phim 1!!" << endl;
		cout << "Chon: ";
		cin >> chon;
		if (chon == 1) {
			delete* it;
			danhSachPhong.erase(it);
			cout << "Da xoa phong hoc co ma " << ma << endl;
		}
		else {
			cout << "Khong muon xoa!!" << endl;
		}
	}
	else {
		cout << "Khong tim thay ma phong can xoa!!" << endl;
	}
}
void tongSoPhongHoc(vector<PhongHoc*> danhSachPhong) {
	int count = 0;
	xuatDanhSach(danhSachPhong);
	for (int i = 0; i < danhSachPhong.size(); i++) {
		count++;
	}
	cout << "Co tong cong " << count << " phong hoc\n";
	cout << endl;

}
void layPhongCo60May(vector<PhongHoc*> danhSachPhong) {
	int count = 0;
	for (int i = 0; i < danhSachPhong.size(); i++) {
		if (PhongMayTinh* mt = dynamic_cast<PhongMayTinh*>(danhSachPhong[i])) {
			if (mt->getMayTinh() == 60) {
				khungMayTinh();
				danhSachPhong[i]->danhSach();
				count++;
			}
		}
	}
	if (count == 0) {
		cout << endl;
		cout << "Khong co phong nao co 60 may.\n";
	}
	else {
		cout << "Co " << count << " phong co 60 may" << endl;
	}
}
void menu() {
	cout << "        QUAN LY PHONG HOC   \n";
	cout << endl;
	cout << "-----------------MENU-----------------" << endl;
	cout << "1.  Nhap cung va xuat danh sach" << endl;
	cout << "2.  Them phong hoc vao danh sach" << endl;
	cout << "3.  Tim kiem phong hoc" << endl;
	cout << "4.  Danh sach phong hoc dat chuan" << endl;
	cout << "5.  Sap xep tang dan theo day nha" << endl;
	cout << "6.  Sap xep giam dan theo dien tich" << endl;
	cout << "7.  Sap xep tang dan theo so bong den" << endl;
	cout << "8.  Cap nhat so may tinh cho phong may tinh" << endl;
	cout << "9.  Xoa phong hoc" << endl;
	cout << "10. Tinh tong so phong hoc" << endl;
	cout << "11. Danh sach cac phong co 60 may" << endl;
	cout << "0.  Thoat chuong trinh                      " << endl;
	cout << "===============================================" << endl;

}
int main() {
	vector<PhongHoc*> danhSachPhong;
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
			danhSachPhong.clear();
			nhapCung(danhSachPhong);
			xuatDanhSach(danhSachPhong);
			break;
		}
		case 2:
		{
			nhapThemPhong(danhSachPhong);
			xuatDanhSach(danhSachPhong);
			break;
		}
		case 3:
		{
			timKiemPhongHoc(danhSachPhong);
			break;
		}
		case 4:
		{
			layPhongHocDatChuan(danhSachPhong);
			break;
		}
		case 5:
		{
			sapXepTangDanTheoDayNha(danhSachPhong);
			break;
		}
		case 6:
		{
			sapXepGiamDanTheoDienTich(danhSachPhong);
			break;
		}
		case 7:
		{
			sapXepTangDanTheoSoBongDen(danhSachPhong);
			break;
		}
		case 8:
		{
			capNhatSoMayTinh(danhSachPhong);
			break;
		}
		case 9:
		{
			xoaPhongHoc(danhSachPhong);
			break;
		}
		case 10:
		{
			tongSoPhongHoc(danhSachPhong);
			break;
		}
		case 11:
		{
			layPhongCo60May(danhSachPhong);
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