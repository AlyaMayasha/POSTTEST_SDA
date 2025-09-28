#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight *next;
    Flight *prev; 
};

Flight *head = nullptr;
Flight *tail = nullptr; 
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
    baru->prev = nullptr;

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
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
    baru->next = nullptr;
    baru->prev = nullptr;

    if (head == nullptr || posisi <= 1) {
        baru->next = head;
        if (head != nullptr) head->prev = baru;
        head = baru;
        if (tail == nullptr) tail = baru;
        cout << ">> Jadwal berhasil disisipkan di posisi awal (list masih kosong)." << endl;
        return;
    }

    Flight *temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp->next == nullptr) { 
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        cout << ">> Mohon maaf list belum cukup panjang untuk menyisipkan jadwal pada posisi ke-5." << endl;
    } else {
        baru->next = temp->next;
        baru->prev = temp;
        temp->next->prev = baru;
        temp->next = baru;
        cout << ">> Jadwal berhasil disisipkan di posisi ke-" << posisi << endl;
    }
}

void hapusAwal() {
    if (head == nullptr) {
        cout << ">> Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight *hapus = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    else tail = nullptr;
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

void cariDetailPenerbangan() {
    if (head == nullptr) {
        cout << ">> Jadwal penerbangan kosong." << endl;
        return;
    }

    string keyword;
    cout << "Masukkan Kode atau Tujuan penerbangan yang ingin dicari: ";
    getline(cin, keyword);

    Flight *temp = head;
    bool ketemu = false;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == keyword || temp->tujuan == keyword) {
            cout << "\n>> Detail Penerbangan Ditemukan:\n";
            cout << "Kode   : " << temp->kodePenerbangan << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            ketemu = true;
            break;
        }
        temp = temp->next;
    }
    if (!ketemu) cout << ">> Data penerbangan tidak ditemukan." << endl;
}

void tampilkanJadwal() {
    if (head == nullptr) {
        cout << ">> Jadwal penerbangan kosong." << endl;
        return;
    }

    cout << "\n===================================================================\n";
    cout << "| No |   Kode Penerbangan   |      Tujuan      |       Status     |\n";
    cout << "===================================================================\n";

    Flight *temp = head;   
    int no = 1;
    while (temp != nullptr) {
        cout << "| " << setw(2) << no++ << " | "
             << setw(21) << left << temp->kodePenerbangan << "| "
             << setw(17) << left << temp->tujuan << "| "
             << setw(17) << left << temp->status << "|\n";
        temp = temp->next; 
    }
    cout << "===================================================================\n";
}

void tampilkanDariBelakang() {
    if (tail == nullptr) {
        cout << ">> Jadwal penerbangan kosong." << endl;
        return;
    }

    cout << "\n===================================================================\n";
    cout << "| No |   Kode Penerbangan   |      Tujuan      |       Status     |\n";
    cout << "===================================================================\n";

    Flight *temp = tail;
    int no = 1;
    while (temp != nullptr) {
        cout << "| " << setw(2) << no++ << " | "
             << setw(21) << left << temp->kodePenerbangan << "| "
             << setw(17) << left << temp->tujuan << "| "
             << setw(17) << left << temp->status << "|\n";
        temp = temp->prev;
    }
    cout << "===================================================================\n";
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
        cout << "| 5. Tampilkan Semua Jadwal (dari depan)                     |\n";
        cout << "| 6. Tampilkan Semua Jadwal (dari belakang)                  |\n";
        cout << "| 7. Cari Detail Penerbangan                                 |\n";
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
            case 6: tampilkanDariBelakang(); break;
            case 7: cariDetailPenerbangan(); break;
            case 0: cout << ">> Anda telah keluar dari program..." << endl; break;
            default: cout << ">> Mohon maaf pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
