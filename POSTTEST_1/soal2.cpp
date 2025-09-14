#include <iostream>
using namespace std;

/*int main() {
    int matriks[3][3];
    int jumlah = 0;

    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matriks[" << i << "][" << j << "] = ";
            cin >> matriks[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) { 
            for (int j = 0; j < 3; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil penjumlahan elemen pada baris genap [0] dan [2] = " << jumlah << endl;

    return 0;
}*/

#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];
    int jumlah = 0;

    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matriks[" << i+1 << "][" << j+1 << "] = "; 
            cin >> matriks[i][j];
        }
    }

    int baris_dihitung = 1; 
    for (int j = 0; j < 3; j++) {
        jumlah += matriks[baris_dihitung][j];
    }

    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil penjumlahan elemen pada baris genap (ke-2) = " << jumlah << endl;

    return 0;
}

