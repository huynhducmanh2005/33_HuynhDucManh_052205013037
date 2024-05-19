#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CauhoiTN
{
private:
    string noiDung;
    string dapAnA;
    string dapAnB;
    string dapAnDung;

public:
    void nhap()
    {
        cout << "Nhap noi dung cau hoi: ";
        cin.ignore();
        getline(cin, noiDung);

        cout << "Nhap dap an A: ";

        getline(cin, dapAnA);

        cout << "Nhap dap an B: ";

        getline(cin, dapAnB);

        cout << "Nhap dap an dung (A/B): ";
        getline(cin, dapAnDung);
    }

    void docfile(ifstream& f)
    {
        getline(f, noiDung);
        cout << noiDung << endl;

        getline(f, dapAnA);
        cout << "A. " << dapAnA << endl;

        getline(f, dapAnB);
        cout << "B. " << dapAnB << endl;

        getline(f, dapAnDung);

    }


    void ghifile(ofstream& f) const
    {
        f << noiDung << endl;
        f << dapAnA << endl;
        f << dapAnB << endl;
        f << dapAnDung << endl;
    }

    bool kiemtra() const
    {
        cout << "Cau hoi: " << noiDung << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;

        string chon;
        cout << "Nhap dap an cua ban (A hoac B): ";
        cin >> chon;

        return (chon == dapAnDung);
    }

    void xuat() const
    {
        cout << "Cau hoi: " << noiDung << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;
        cout << "Dap an dung: " << dapAnDung << endl;
    }

    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2)
{
    return (cau1.noiDung == cau2.noiDung &&
        cau1.dapAnA == cau2.dapAnA &&
        cau1.dapAnB == cau2.dapAnB &&
        cau1.dapAnDung == cau2.dapAnDung);
}


int menu() {
    int luaChon;
    cout << "===== MENU =====" << endl;
    cout << "1. Tao mot de thi trac nghiem moi" << endl;
    cout << "2. Them mot cau hoi moi vao de thi hien hanh" << endl;
    cout << "3. In danh sach cau hoi hien co trong de thi" << endl;
    cout << "4. Luu danh sach cau hoi vao file *.TTN" << endl;
    cout << "5. Doc noi dung mot file *.TTN vao bo nho" << endl;
    cout << "6. Cho thi va tinh so cau tra loi dung" << endl;
    cout << "7. Thoat chuong trinh" << endl;
    cout << "================" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> luaChon;
    return luaChon;
}

int main()
{
    vector<CauhoiTN> danhSachCauHoi;
    int luaChon;

    do
    {
        luaChon = menu();

        switch (luaChon) {
        case 1:
        {
            int soLuong;
            cout << "Nhap so luong cau hoi: ";
            cin >> soLuong;
            for (int i = 0; i < soLuong; i++) {
                CauhoiTN cauhoi;
                cauhoi.nhap();
                danhSachCauHoi.push_back(cauhoi);
            }
            cout << "Da tao mot de thi trac nghiem moi." << endl;
            break;
        }
        case 2:
        {
            CauhoiTN cauhoi;
            cauhoi.nhap();
            danhSachCauHoi.push_back(cauhoi);
            cout << "Da them mot cau hoi moi vao de thi hien hanh." << endl;
            break;
        }
        case 3:
        {
            cout << "Danh sach cau hoi hien co trong de thi:" << endl;
            for (const auto& cauhoi : danhSachCauHoi) {
                cauhoi.xuat();
                cout << endl;
            }
            break;
        }
        case 4:
        {
            string tenFile;
            cout << "Nhap ten file (*.TTN) de luu danh sach cau hoi: ";
            cin >> tenFile;

            ofstream file(tenFile);
            if (file.is_open()) {
                for (const auto& cauhoi : danhSachCauHoi) {
                    cauhoi.ghifile(file);
                }
                file.close();
                cout << "Da luu danh sach cau hoi vao file " << tenFile << endl;
            }
            else {
                cout << "Khong the mo file de ghi." << endl;
            }
            break;
        }
        case 5:
        {
            string tenFile;
            cout << "Nhap ten file (*.TTN) de doc noi dung: ";
            cin >> tenFile;

            ifstream file(tenFile);
            if (file.is_open())
            {
                danhSachCauHoi.clear();
                while (!file.eof())
                {
                    CauhoiTN cauhoi;
                    cauhoi.docfile(file);
                    danhSachCauHoi.push_back(cauhoi);
                }
                file.close();
                cout << "Da doc noi dung tu file " << tenFile << " vao bo nho." << endl;
            }
            else
            {
                cout << "Khong the mo file de doc." << endl;
            }
            break;
        }
        case 6:
        {
            int soCauTraLoiDung = 0;
            for (const auto& cauhoi : danhSachCauHoi)
            {
                if (cauhoi.kiemtra())
                {
                    soCauTraLoiDung++;
                }
            }
            cout << "So cau tra loi dung: " << soCauTraLoiDung << endl;
            break;
        }
        case 7:
            cout << "Tam biet!";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            break;
        }

        cout << endl;
    } while (luaChon != 7);

    return 0;
}