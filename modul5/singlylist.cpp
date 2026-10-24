
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

address findElm(List L, infotype x) {
    address P = L.First;

    while (P != nullptr) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

int totalInfo(List L) {
    address P = L.First;
    int total = 0;

    while (P != nullptr) {
        total = total + P->info;
        P = P->next;
    }

    return total;
}
