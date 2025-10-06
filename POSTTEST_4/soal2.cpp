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

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false; 
            char topChar = pop(stackTop);

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;


    return 0;
}

/* Penjelasan : for (char c : expr) artinya melakukan perulangan untuk setiap karakter di dalam string expr.
                Lalu pada line selanjutnya jika karakter yang sedang dibaca kurung buka maka karakter akan dimasukkan ke dalam stack.
                Stack menyimpan urutan kurung buka yang nantinya akan dicocokkan dengan kurung tutup yang muncul setelahnya.
                Jika karakter yang ditemukan adalah kurung tutup, program akan memeriksa apakah stack kosong. 
                if (stackTop == nullptr) return false; artinya jika kosong berarti tidak ada pasangan kurung buka yang sesuai, dan fungsi langsung mengembalikan false. 
                char topChar = pop(stackTop); artinya jika tidak kosong, satu elemen teratas akan diambil dari stack dan dibandingkan apakah pasangan kurungnya cocok. 
                Jika tidak cocok, fungsi mengembalikan false. 
                Setelah semua karakter diperiksa, kondisi return (stackTop == nullptr) memastikan tidak ada kurung buka yang tersisa di dalam stack jika stack kosong, semua kurung sudah berpasangan dengan benar dan string dinyatakan seimbang.*/
