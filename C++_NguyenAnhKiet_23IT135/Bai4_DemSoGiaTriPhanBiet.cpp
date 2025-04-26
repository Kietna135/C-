#include <iostream>
#include <set>
#include <limits>
using namespace std;

// Ham nhap so nguyen duong n
int nhapSND() {
    int n;
    while (true) {
        cout << "Nhap so luong phan tu n > 0: ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Gia tri khong hop le. Vui long nhap lai.\n";
        } else {
            return n;
        }
    }
}

int main() {
    int n = nhapSND();

    int* arr = new int[n];
    cout << "Nhap " << n << " phan tu cua mang:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    set<int> TGT; // dung set de loai bo gia tri trung lap, TGT là tap gia tri 

    for (int i = 0; i < n; ++i) {
        TGT.insert(arr[i]);
    }

    int PB = TGT.size(); // PB : so phan biet

    if (PB == 0) {
        cout << "Mang rong. Khong co gia tri nao.\n";
    } else if (PB == 1) {
        cout << "Tat ca gia tri trong mang giong nhau.\n";
        cout << "Mang rong\n";
    } else {
        cout << "So luong gia tri phan biet trong mang la: " << soPhanBiet << "\n";
    }

    delete[] arr;
    return 0;
}

