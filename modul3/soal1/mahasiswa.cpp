
#include "mahasiswa.h"

float hitungNilaiAkhir(Mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

void inputMahasiswa(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;

        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);

        cout << "NIM: ";
        cin >> mhs[i].nim;

        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i]);
    }
}

void tampilMahasiswa(Mahasiswa mhs[], int n) {
    cout << "\n=== Data Mahasiswa ===" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nNama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai UTS: " << mhs[i].uts << endl;
        cout << "Nilai UAS: " << mhs[i].uas << endl;
        cout << "Nilai Tugas: " << mhs[i].tugas << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
}
