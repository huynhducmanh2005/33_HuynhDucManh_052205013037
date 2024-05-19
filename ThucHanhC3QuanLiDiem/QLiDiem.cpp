#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    int soBuoiVang;
    float diemTH;
    float diemGK;
    float diemQT;
};

double tinhDiemQT(const SinhVien& sv) {
    if (sv.soBuoiVang <= 5) {
        return (10 - sv.soBuoiVang * 2) * 0.2 + sv.diemTH * 0.3 + sv.diemGK * 0.5;
    }
    else {
        return 0;
    }
}
SinhVien nhapSinhVien() {
    SinhVien sv;
    cout << "Nhap ma SV: ";
    cin.ignore();
    getline(cin, sv.maSV);
    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap so buoi vang: ";
    cin >> sv.soBuoiVang;
    cout << "Nhap diem TH: ";
    cin >> sv.diemTH;
    cout << "Nhap diem GK: ";
    cin >> sv.diemGK;
    return sv;
}
void xuatSinhVien(const SinhVien& sv) {
    double diemQT = tinhDiemQT(sv);
    cout << "Ma SV: " << sv.maSV << endl;
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "So buoi vang: " << sv.soBuoiVang << endl;
    cout << "Diem TH: " << sv.diemTH << endl;
    cout << "Diem GK: " << sv.diemGK << endl;
    cout << "Diem QT: " << sv.diemQT << endl;
    cout << endl;
}
vector<SinhVien> nhapDanhSachSinhVien() {
    vector<SinhVien> danhSachSV;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        SinhVien sv = nhapSinhVien();
        danhSachSV.push_back(sv);
    }
    return danhSachSV;
}
void xuatDanhSachSinhVien(const vector<SinhVien>& danhSachSV) {
    for (const auto& sv : danhSachSV) {
        xuatSinhVien(sv);
    }
}

void inDanhSachDuDieuKien(const vector<SinhVien>& danhSachSV) {
    cout << "Danh sach sinh vien du dieu kien du thi:" << endl;
    for (const SinhVien& sv : danhSachSV) {
        double diemQT = tinhDiemQT(sv);
        if (diemQT >= 3) {
            xuatSinhVien(sv);
        }
    }
}

void inDanhSachNguyen(const vector<SinhVien>& danhSachSV) {
    cout << "Danh sach sinh vien co ho la 'Nguyen':" << endl;
    for (const SinhVien& sv : danhSachSV) {
        if (sv.hoTen.substr(0, 6) == "Nguyen") {
            xuatSinhVien(sv);
        }
    }
}

void inDanhSachTrungTen(const vector<SinhVien>& danhSachSV) {
    cout << "Danh sach sinh vien co cung ten voi mot sinh vien khac:" << endl;

    vector<string> dsTen;
    for (const SinhVien& sv : danhSachSV) {
        dsTen.push_back(sv.hoTen);
    }

    sort(dsTen.begin(), dsTen.end());
    auto last = unique(dsTen.begin(), dsTen.end());

    for (auto it = dsTen.begin(); it != last; ++it) {
        if (count(dsTen.begin(), last, *it) > 1) {
            cout << "Ho ten: " << *it << endl;
        }
    }
}

void ghiSinhVienVaoFile(const vector<SinhVien>& danhSachSV, const string& tenFile) {
    ofstream file(tenFile, ios::app);
    if (file.is_open()) {
        for (const auto& sv : danhSachSV) {
            file << sv.maSV << endl;
            file << sv.hoTen << endl;
            file << sv.soBuoiVang << endl;
            file << sv.diemTH << endl;
            file << sv.diemGK << endl;
        }
        file.close();
        cout << "Ghi sinh vien vao file thanh cong." << endl;
    }
    else {
        cout << "Khong the mo file de ghi." << endl;
    }
}

void docDanhSachSinhVienTuFile(vector<SinhVien>& danhSachSV, const string& tenFile) {
    ifstream file(tenFile);
    if (file.is_open()) {
        string line;
        SinhVien sv;
        while (getline(file, sv.maSV)) {
            getline(file, sv.hoTen);
            file >> sv.soBuoiVang;
            file >> sv.diemTH;
            file >> sv.diemGK;
            file.ignore();

            danhSachSV.push_back(sv);
        }
        file.close();
    }
    else {
        cout << "Khong the mo file de doc." << endl;
    }
}

int main() {
    vector<SinhVien> danhSachSV;
    int n;
    SinhVien sv;
    int choice;
    do {
        cout << "=============================" << endl;
        cout << "QUAN LY DIEM SINH VIEN" << std::endl;
        cout << "1. Nhap danh sach sinh vien" << endl;
        cout << "2. Xuat danh sach sinh vien" << endl;
        cout << "3. Ghi danh sach sinh vien vao file" << std::endl;
        cout << "4. Doc danh sach sinh vien tu file" << std::endl;
        cout << "5. In danh sach sinh vien du dieu kien du thi" << endl;
        cout << "6. In danh sach sinh vien co ho la 'Nguyen'" << endl;
        cout << "7. In danh sach sinh vien co cung ten voi mot sinh vien khac" << endl;
        cout << "0. Thoat" << endl;
        cout << "=============================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            danhSachSV = nhapDanhSachSinhVien();
            break;
        }
        case 2: {
            cout << "Danh sach sinh vien:" << endl;

            xuatDanhSachSinhVien(danhSachSV);
            break;
        }
        case 3: {
            string tenFile;
            cout << "Nhap ten file: ";
            cin >> tenFile;
            ghiSinhVienVaoFile(danhSachSV, tenFile);
            break;
        }
        case 4: {
            string tenFile;
            cout << "Nhap ten file: ";
            cin >> tenFile;
            danhSachSV.clear();
            docDanhSachSinhVienTuFile(danhSachSV, tenFile);
            break;
        }
        case 5: {
            inDanhSachDuDieuKien(danhSachSV);
            break;
        }
        case 6: {
            inDanhSachNguyen(danhSachSV);
            break;
        }
        case 7: {
            inDanhSachTrungTen(danhSachSV);
            break;
        }
        case 0: {
            cout << "Tam biet!" << endl;
            break;
        }
        default: {
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;

}