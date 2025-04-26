#include <iostream>
#include <limits>
using namespace std;

// Khai bao mang de luu cac gia tri Fibonacci toi da 31 phan tu vi chi tinh den F(30)
int fib[31] = {0};

// Ham de quy co toi uu bang mang memoization
int tinhFibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    if (fib[n] != 0) return fib[n]; // neu da tinh thi tra ve luon
    fib[n] = tinhFibonacci(n - 1) + tinhFibonacci(n - 2); // luu ket qua vao mang
    return fib[n];
}

// Ham nhap so nguyen duong n sao cho 1 <= n <= 30
int nhapSoNguyenHopLe() {
    int n;
    while (true) {
        cout << "Nhap so nguyen n 1 <= n <= 30: ";
        cin >> n;

        if (cin.fail() || n < 1 || n > 30) {
            cin.clear(); // xoa co loi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bo qua phan con lai trong dong
            cout << "Gia tri khong hop le. Vui long nhap lai.\n";
        } else {
            return n;
        }
    }
}

int main() {
    // Nhap n
    int n = nhapSoNguyenHopLe();

    cout << "\nDay Fibonacci tu F(1) den F(" << n << "):\n";

    // In day Fibonacci tu F(1) den F(n)
    for (int i = 1; i <= n; ++i) {
        cout << "F(" << i << ") = " << tinhFibonacci(i) << endl;
    }

    return 0;
}

