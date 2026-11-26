#include <iostream>
#include "bstree.h"

using namespace std;

int main() {

    // Latihan 1 dan 2
    cout << "LATIHAN 1 DAN 2" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    cout << "InOrder : ";
    printInorder(root);

    cout << endl;
    cout << "Jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root, 0) << endl;
    cout << "Kedalaman : " << hitungKedalaman(root, 0) << endl;


    // Latihan 3
    cout << "\nLATIHAN 3" << endl;

    address root2 = Nil;

    insertNode(root2, 6);
    insertNode(root2, 4);
    insertNode(root2, 7);
    insertNode(root2, 2);
    insertNode(root2, 5);
    insertNode(root2, 1);
    insertNode(root2, 3);

    cout << "Pre-order : ";
    printPreorder(root2);

    cout << endl;

    cout << "Post-order : ";
    printPostorder(root2);

    cout << endl;

    return 0;
}