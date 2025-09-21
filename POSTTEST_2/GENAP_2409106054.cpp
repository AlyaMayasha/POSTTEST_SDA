#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight *next;
};

Flight *head = nullptr;
int counter = 0; 

string generateKode() {
    string base = "JT-054";
    if (counter == 0) {
        counter++;
        return base;
    } else {
        return base + "-" + to_string(counter++);
    }
}

void tambahkanJadwal() {
    Flight *baru = new Flight;
    baru->kodePenerbangan = generateKode();
    cout << "Silahkan masukkan tujuan penerbangan: ";
    getline(cin, baru->tujuan);
    cout << "Silahkan masukkan status penerbangan (Tepat Waktu/Terlambat/Dalam Penerbangan): ";
    getline(cin, baru->status);
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Flight *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << ">> Jadwal penerbangan berhasil ditambahkan dengan kode: " 
         << baru->kodePenerbangan << endl;
}

void sisipkanJadwal() {
    int posisi = 5; 
    Flight *baru = new Flight;
    baru->kodePenerbangan = generateKode();
    cout << "Silahkan masukkan tujuan penerbangan: ";
    getline(cin, baru->tujuan);
    cout << "Silahkan masukkan status penerbangan (Tepat Waktu/Terlambat/Dalam Penerbangan): ";
    getline(cin, baru->status);

    if (head == nullptr || posisi <= 1) {
        baru->next = head;
        head = baru;
        cout << ">> Jadwal berhasil disisipkan di posisi awal." << endl;
        return;
    }

    Flight *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << ">> Mohon maaf posisi melebihi panjang list, silahkan tambahkan jadwal penerbangan lagi." << endl;
        tambahkanJadwal();
        return;
    }

    baru->next = temp->next;
    temp->next = baru;
    cout << ">> Jadwal berhasil disisipkan di posisi ke-" << posisi << endl;
}

void hapusAwal() {
    if (head == nullptr) {
        cout << ">> Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight *hapus = head;
    head = head->next;
    cout << ">> Jadwal penerbangan dengan kode " << hapus->kodePenerbangan << " berhasil dihapus." << endl;
    delete hapus;
}

void updateStatusPenerbangan() {
    if (head == nullptr) {
        cout << ">> Tidak ada jadwal." << endl;
        return;
    }

    string kode;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    getline(cin, kode);

    Flight *temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "Status penerbangan saat ini: " << temp->status << endl;
            cout << "Masukkan status penerbangan baru: ";
            getline(cin, temp->status);
            cout << ">> Status penerbangan " << kode << " berhasil diupdate." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << ">> Jadwal penerbangan dengan kode " << kode << " tidak ditemukan." << endl;
}

void tampilkanJadwal() {
    if (head == nullptr) {
        cout << ">> Jadwal penerbangan kosong." << endl;
        return;
    }

    cout << "\n==================================================================\n";
    cout << "| No |   Kode Penerbangan   |      Tujuan      |       Status     |\n";
    cout << "==================================================================\n";

    Flight *temp = head;
    int no = 1;
    while (temp != nullptr) {
        cout << "| " << setw(2) << no++ << " | "
             << setw(18) << left << temp->kodePenerbangan << "| "
             << setw(20) << left << temp->tujuan << "| "
             << setw(15) << left << temp->status << "|\n";
        temp = temp->next;
    }
    cout << "==================================================================\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|           FLIGHT SCHEDULE MAYASHA AIRLINE                  |\n";
        cout << "|             [ Alya Mayasha - 2409106054 ]                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Update Status Penerbangan                               |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Silahkan pilih menu: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1: tambahkanJadwal(); break;
            case 2: sisipkanJadwal(); break;
            case 3: hapusAwal(); break;
            case 4: updateStatusPenerbangan(); break;
            case 5: tampilkanJadwal(); break;
            case 0: cout << ">> Anda telah keluar dari program..." << endl; break;
            default: cout << ">> Mohon maaf pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
