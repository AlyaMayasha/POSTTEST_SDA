#include <iostream>
using namespace std;


void balikBilangan(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int n = 7; 
    int data[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Bilangan prima awal: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    balikBilangan(data, n); 

    cout << "Bilangan prima setelah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
