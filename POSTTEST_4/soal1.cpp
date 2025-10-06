#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; 
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    for (char c : s) {
        push(stackTop, c);
    }
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    return 0;
}

/*Penjelasan : for (char c : s) artinya perulangan untuk setiap karakter di dalam string.
               lalu push(stackTop, c) akan menambahkan karakter ke atas tumpukan stack, sehingga dapat kita ketahui, huruf terakhir berada di posisi paling atas.  
               Selanjutnya, selama stack masih ada isinya, karakter diambil kembali dari atas stack lalu ditambahkan ke variabel reversed dengan perulangan while.  
               Setelah semua karakter dikeluarkan, string reversed dikembalikan sebagai hasil akhir.*/
