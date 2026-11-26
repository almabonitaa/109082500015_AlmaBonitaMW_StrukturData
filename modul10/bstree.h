#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define Nil nullptr

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

void printInorder(address root);
void InOrder(address root);
void printPreorder(address root);
void printPostorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

// Fungsi pendukung nama pada contoh modul
int hitungNode(address root);
int hitungTotal(address root);

#endif