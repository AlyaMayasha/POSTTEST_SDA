#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

int findMinValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; 
    return 0;
}

/*Penjelasan : if (root == nullptr) artinya jika tree kosong, fungsi langsung mengembalikan -1 sebagai penanda tidak ada nilai yang bisa dicari. 
               Lalu Node* current = root berfungsi menyimpan posisi awal di node root. 
               Selanjutnya, while (current->left != nullptr) akan menelusuri node ke arah kiri selama masih ada anak kiri. 
               Karena pada BST nilai terkecil selalu berada di paling kiri, ketika perulangan berhenti, current berada pada node dengan nilai minimum. 
               return current->data mengembalikan nilai terkecil.*/
