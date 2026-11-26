#include "bstree.h"

// Membuat node baru
address alokasi(infotype x) {
    address baru = new Node;

    baru->info = x;
    baru->left = Nil;
    baru->right = Nil;

    return baru;
}

// Memasukkan data ke dalam BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    }
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Mencari node berdasarkan nilai
address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    }

    if (x < root->info) {
        return findNode(x, root->left);
    }
    else {
        return findNode(x, root->right);
    }
}

// Menampilkan data secara Inorder
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Menyesuaikan nama fungsi dengan contoh main.cpp modul
void InOrder(address root) {
    printInorder(root);
}

// Menampilkan data secara Preorder
void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Menampilkan data secara Postorder
void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}

// Menghitung jumlah node
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }

    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

// Menghitung total nilai seluruh node
int hitungTotalInfo(address root, int start) {
    if (root == Nil) {
        return start;
    }

    start += root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);

    return start;
}

// Menghitung kedalaman maksimal tree
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }

    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    if (kiri > kanan) {
        return kiri;
    }
    else {
        return kanan;
    }
}

// Fungsi pendukung sesuai nama pada contoh modul
int hitungNode(address root) {
    return hitungJumlahNode(root);
}

int hitungTotal(address root) {
    return hitungTotalInfo(root, 0);
}