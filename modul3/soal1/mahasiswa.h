
#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(Mahasiswa m);
void inputMahasiswa(Mahasiswa mhs[], int n);
void tampilMahasiswa(Mahasiswa mhs[], int n);

#endif
