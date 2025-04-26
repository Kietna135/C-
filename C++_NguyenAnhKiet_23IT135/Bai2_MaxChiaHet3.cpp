#include <iostream>
#include <limits>  // dùng numeric_limits
using namespace std;

// Hàm kiem tra nhap vào so n co phai la so nguyen duong?
int SND() {
    int n;
    while (true) {
        cout << "Nhap so luong phan tu (n > 0): ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bo qua nhung gì còn lai trong dòng
            cout << "Gia tri khong hop le. Vui long nhap lai.\n";
        } else {
            return n;
        }
    }
}

int main() {
    int n = SND();

    int* arr = new int[n];

    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    int maxCHC3 = -1e9;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        if (arr[i] % 3 == 0) {
            if (!found || arr[i] > maxCHC3) {
                maxCHC3 = arr[i];
                found = true;
            }
        }
    }

    if (found) {
        cout << "So lon nhat chia het cho 3 la: " << maxCHC3 << endl;
    } else {
        cout << "Khong co so nao chia het cho 3." << endl;
    }

    delete[] arr; // giai phong bo nho
    return 0;
}

