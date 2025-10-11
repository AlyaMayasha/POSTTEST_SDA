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

int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; 
    return 0;
}

/*Penjelasan : if (root == nullptr) artinya jika node kosong, fungsi akan langsung mengembalikan 0 sebagai tanda tidak ada node yang dihitung. 
               Selanjutnya, return 1 + countNodes(root->left) + countNodes(root->right) akan menghitung 1 untuk node saat ini, 
               lalu menjumlahkan dengan total node di subtree kiri dan kanan secara rekursif, dan seluruh node dalam tree akan terhitung sampai ke level paling bawah.*/
