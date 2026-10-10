
#include <iostream>
#include "array.h"
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3],
                int baris, int kolom) {
    int sementara = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = sementara;
}

void tukarPointer(int *p1, int *p2) {
    int sementara = *p1;
    *p1 = *p2;
    *p2 = sementara;
}
