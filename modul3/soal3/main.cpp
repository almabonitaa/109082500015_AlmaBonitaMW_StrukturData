
#include <iostream>
#include "array.h"
using namespace std;

int main() {
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arr2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *p1 = &arr1[0][0];
    int *p2 = &arr2[0][0];

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilArray(arr1);

    cout << "\nArray 2 sebelum ditukar:" << endl;
    tampilArray(arr2);

    tukarArray(arr1, arr2, 1, 1);

    cout << "\nArray setelah menukar posisi baris 2 kolom 2:"
         << endl;

    cout << "Array 1:" << endl;
    tampilArray(arr1);

    cout << "\nArray 2:" << endl;
    tampilArray(arr2);

    tukarPointer(p1, p2);

    cout << "\nSetelah menukar nilai pointer:" << endl;
    cout << "Nilai arr1[0][0] = " << arr1[0][0] << endl;
    cout << "Nilai arr2[0][0] = " << arr2[0][0] << endl;

    return 0;
}
