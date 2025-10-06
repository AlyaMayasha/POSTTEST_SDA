#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if (front == nullptr) {
        front = rear = newNode; 
    } 
    else {
        rear->next = newNode;  
        rear = newNode;         
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; 

    Node* temp = front;             
    string doc = temp->document;    
    front = front->next;            

    if (front == nullptr)
        rear = nullptr;

    delete temp;                    
    return doc;                   
}

void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}

/*Penjelasan : if (front == nullptr) artinya antrian masih kosong.
               front = rear = newNode; artinya merujuk front dan rear ke newNode.
               Lalu jika antrian tidak kosong, kita dapat menyambungkan rear ke node baru.
               rear = newNode; artinya memindahkan posisi rear supaya menunjuk ke node paling baru.

               Node* temp = front; artinya menyimpan alamat node paling depan ke pointer sementara yaitu temp.
               string doc = temp->document; artinya menyimpan data dokumen dari node yang akan dihapus ke variabel doc.
               Setelah itu menggeser pointer front ke node berikutnya.
               if (front == nullptr) kondisi ini akan memeriksa apakah queue kosong setelah dihapus.
               Jika iya (front == nullptr), maka rear juga harus diset ke nullptr.
               Selanjutnya menghapus node lama dari memori dengan delete temp dan mengembalikan nama dokumen yang dikeluarkan dari antrian dengan return doc.*/
