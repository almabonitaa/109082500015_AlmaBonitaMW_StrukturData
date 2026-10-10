
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa mhs[MAX];
    int n;

    cout << "Jumlah mahasiswa (maksimal 10): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 0;
    }

    inputMahasiswa(mhs, n);
    tampilMahasiswa(mhs, n);

    return 0;
}
