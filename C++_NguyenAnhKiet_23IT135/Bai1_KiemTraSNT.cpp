#include <iostream>
using namespace std;

// Ham Kiem Tra So Nguyen To
bool SNT(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Nhap mot so nguyen duong N: ";
    cin >> N;

    if (N <= 2) {
        cout << "Khong co so nguyen to" << endl;
    } else {
        cout << "Cac so nguyen to nho hon " << N << " la: ";
        for (int i = 2; i < N; ++i) {
            if (SNT(i)) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

