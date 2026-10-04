#include <iostream>
using namespace std;

#define MAX 10

int maksimum(int arr[]) {
    int max = arr[0];

    for (int i = 1; i < MAX; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int minimum(int arr[]) {
    int min = arr[0];

    for (int i = 1; i < MAX; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void rataRata(int arr[], float &rata) {
    int jumlah = 0;

    for (int i = 0; i < MAX; i++) {
        jumlah = jumlah + arr[i];
    }

    rata = (float) jumlah / MAX;
}

int main() {
    int arr[MAX] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};

    int pilihan;
    float rata;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "\nIsi array:" << endl;

            for (int i = 0; i < MAX; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
            break;

        case 2:
            cout << "\nNilai maksimum = "
                 << maksimum(arr) << endl;
            break;

        case 3:
            cout << "\nNilai minimum = "
                 << minimum(arr) << endl;
            break;

        case 4:
            rataRata(arr, rata);

            cout << "\nNilai rata-rata = "
                 << rata << endl;
            break;

        case 5:
            cout << "\nProgram selesai." << endl;
            break;

        default:
            cout << "\nPilihan tidak tersedia." << endl;
        }

    } while (pilihan != 5);

    return 0;
}