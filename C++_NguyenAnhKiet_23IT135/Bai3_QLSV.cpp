#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

struct SinhVien {
    string ten;
    float toan, ly, hoa;
    float diemTB;
};

// Ham nhap so nguyen duong n
int nhapSLSV() {   // SLSV la so luong sinh vien
    int n;
    while (true) {
        cout << "Nhap so luong sinh vien n > 0: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Gia tri khong hop le. hay nhap lai.\n";
        } else {
            return n;
        }
    }
}

// Ham nhap diem va kiem tra hop le trong khoang [0 10]
float nhapDiem(string mon) {
    float diem;
    while (true) {
        cout << "Nhap so diem " << mon << " tren thang diem (0 - 10): ";
        cin >> diem;
        if (cin.fail() || diem < 0 || diem > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Diem khong hop le. Vui long nhap lai.\n";
        } else {
            return diem;
        }
    }
}

int main() {
    int n = nhapSLSV();
    SinhVien* ds = new SinhVien[n];

    // Nhap danh sach sinh vien
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        cin.ignore();
        cout << "Nhap ten: ";
        getline(cin, ds[i].ten);
        ds[i].toan = nhapDiem("Toan");
        ds[i].ly = nhapDiem("Ly");
        ds[i].hoa = nhapDiem("Hoa");
        ds[i].diemTB = (ds[i].toan + ds[i].ly + ds[i].hoa) / 3.0;
    }

    // In sinh vien co diem TB >= 8
    cout << "\nDanh sach sinh vien co diem trung binh >= 8:\n";
    cout << left << setw(25) << "Ten"
         << setw(10) << "Toan"
         << setw(10) << "Ly"
         << setw(10) << "Hoa"
         << setw(12) << "Diem TB" << endl;

    bool SV = false;
    for (int i = 0; i < n; ++i) {
        if (ds[i].diemTB >= 8.0) {
            SV = true;
            cout << left << setw(25) << ds[i].ten
                 << setw(10) << ds[i].toan
                 << setw(10) << ds[i].ly
                 << setw(10) << ds[i].hoa
                 << setw(12) << fixed << setprecision(2) << ds[i].diemTB << endl;
        }
    }

    if (!SV) {
        cout << "Khong co sinh vien nao co diem trung binh >= 8.\n";
    }

    delete[] ds;
    return 0;
}

