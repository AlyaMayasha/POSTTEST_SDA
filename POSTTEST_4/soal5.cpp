#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }
    Node* head = head_ref;
    Node* tail = head_ref->prev; 
    Node* head_next = head->next; 
    Node* tail_prev = tail->prev; 

    if (head_next == tail) {
        head_ref = tail;
        return;
    }
    head_next->prev = tail;
    tail->next = head_next;

    tail_prev->next = head;
    head->prev = tail_prev;

    head->next = tail;
    tail->prev = head;

    head_ref = tail;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}

/*Penjelasan : Node* head_next = head->next artinya menyimpan alamat node yang berada setelah node head ke variabel head_next.
               Node* tail_prev = tail->prev artinya menyimpan alamat node yang berada sebelum node tail ke variabel tail_prev.
               if (head_next == tail) artinya memeriksa apakah node head dan tail bersebelahan.
               Jika iya berarti menukar posisi head dengan tail.
               head_ref = tail artinya menjadikan tail sebagai head baru, lalu return untuk mengakhiri fungsi.

               head_next->prev = tail artinya node setelah head sekarang menunjuk ke tail sebagai node sebelumnya.
               tail->next = head_next artinya node tail sekarang menunjuk ke node yang sebelumnya berada setelah head.

               tail_prev->next = head artinya node sebelum tail sekarang menunjuk ke head.
               head->prev = tail_prev artinya node head sekarang menunjuk ke node sebelum tail.

               head->next = tail artinya node head sekarang menunjuk ke node tail sebagai node berikutnya.
               tail->prev = head artinya node tail sekarang menunjuk ke node head sebagai node sebelumnya.
               Lalu memperbarui pointer head utama agar menunjuk ke node tail dengan head_ref = tail, menandakan bahwa posisi head dan tail telah ditukar dalam circular doubly linked list.*/