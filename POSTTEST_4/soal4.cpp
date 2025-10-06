#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* last = head_ref->prev; 
    if (data < head_ref->data) {
        newNode->next = head_ref;
        newNode->prev = last;
        last->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode; 
        return;
    }
    Node* current = head_ref;
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    Node *current = head_ref;
    do 
    {
        cout << current->data << " ";
        current = current->next;
    } 
    while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);
    return 0;
}

/*Penjelasan : Node* last = head_ref->prev artinya menyimpan alamat node terakhir dalam list, node terakhir dapat diakses dari head_ref->prev karena circular.
               if (data < head_ref->data) artinya jika data yang ingin disisipkan lebih kecil dari data head, maka node baru harus diletakkan sebelum head agar urutan tetap ascending.
               newNode->next = head_ref artinya node baru akan menunjuk ke node head sebagai node berikutnya.
               newNode->prev = last artinya node baru akan menunjuk ke node terakhir sebagai node sebelumnya.
               last->next = newNode artinya node terakhir sekarang menunjuk ke node baru.
               head_ref->prev = newNode artinya node head lama sekarang menunjuk ke node baru sebagai node sebelumnya.
               head_ref = newNode artinya node baru menjadi head baru dalam list karena memiliki nilai paling kecil.

               Node* current = head_ref artinya membuat pointer untuk traversal dari head.
               lalu dilakukan perulangan while (current->next != head_ref && current->next->data < data) artinya selama node berikutnya belum kembali ke head dan data pada node berikutnya masih lebih kecil dari data yang ingin disisipkan, gunanya mencari posisi yang tepat untuk menyisipkan node baru.
               newNode->next = current->next artinya node baru menunjuk ke node setelah current.
               newNode->prev = current artinya node baru menunjuk ke current sebagai node sebelumnya.
               current->next->prev = newNode artinya node setelah current sekarang menunjuk ke node baru sebagai node sebelumnya.
               current->next = newNode artinya node current sekarang menunjuk ke node baru sebagai node berikutnya.
               Dengan begitu node dapat disisipkan diposisi yg tepat. */
