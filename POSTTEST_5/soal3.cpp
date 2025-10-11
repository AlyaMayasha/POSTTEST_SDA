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

int findMaxValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; 
    return 0;
}

/*Penjelasan : if (root == nullptr) artinya jika tree kosong, fungsi akan langsung mengembalikan -1 sebagai penanda tidak ada nilai yang bisa dicari. 
               Kemudian Node* current = root menyimpan posisi awal di node root. 
               while (current->right != nullptr) akan terus bergerak ke node kanan selama masih ada anak kanan. 
               Karena pada BST nilai terbesar selalu berada di paling kanan, ketika perulangan berhenti, current sudah berada pada node dengan nilai maksimum. 
               return current->data mengembalikan nilai terbesar.*/
