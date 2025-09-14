#include <iostream>
#include <string>
using namespace std;

/*struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    cout << "Silahkan input data 4 mahasiswa! ^_^\n";
    for (int i = 0; i < N; i++) {
        cout << "\nMahasiswa ke-" << i+1 << ":\n";
        cout << "Nama : ";
        cin.ignore(i == 0 ? 0 : 1, '\n'); 
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }

    cout << "\nData Mahasiswa setelah diurutkan berdasarkan IPK secara ascending :\n";
    for (int i = 0; i < N; i++) {
        cout << i+1 << ". " 
             << mhs[i].nama << " || NIM: " << mhs[i].nim 
             << " || IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}*/

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    int N = 4; 
    Mahasiswa mhs[4]; 

    cout << "Silahkan input data 4 mahasiswa! ^_^\n";
    for (int i = 0; i < N; i++) {
        cout << "\nMahasiswa ke-" << i+1 << ":\n";
        cout << "Nama : ";
        cin.ignore(i == 0 ? 0 : 1, '\n'); 
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }

    cout << "\nData Mahasiswa setelah diurutkan berdasarkan IPK secara ascending :\n";
    for (int i = 0; i < N; i++) {
        cout << i+1 << ". "
             << mhs[i].nama << " || NIM: " << mhs[i].nim 
             << " || IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}

