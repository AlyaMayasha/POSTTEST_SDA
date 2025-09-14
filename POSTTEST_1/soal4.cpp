#include <iostream>
using namespace std;

void tukarNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "Silahkan masukkan nilai pertama (x): ";
    cin >> x;
    cout << "Silahkan masukkan nilai kedua (y): ";
    cin >> y;

    cout << "\nSebelum pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukarNilai(x, y);

    cout << "\nSetelah pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
