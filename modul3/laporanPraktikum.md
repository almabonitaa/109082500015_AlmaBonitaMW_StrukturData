# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE</h1>

<p align="center">Alma Bonita Mia Wardhana - 109082500015</p>

## Dasar Teori

Pada modul ini dibahas konsep **Abstract Data Type (ADT)** yang digunakan untuk membuat dan mengatur tipe data beserta operasi yang dapat dilakukan terhadap data tersebut. ADT membantu program menjadi lebih terstruktur karena tipe data, fungsi atau prosedur, dan program utama dapat dipisahkan. Dalam C++, ADT dapat diterapkan menggunakan `struct`, fungsi, dan prosedur.

### A. Konsep Abstract Data Type (ADT)

ADT merupakan tipe data yang memiliki sekumpulan operasi dasar atau primitif untuk mengolah data tersebut. ADT tidak hanya berisi tipe data, tetapi juga aturan dan operasi yang dapat dilakukan terhadap tipe data tersebut.

#### 1. Pengertian ADT

#### 2. Tipe Data dan Primitif pada ADT

#### 3. Jenis-Jenis Primitif ADT

### B. Implementasi ADT

ADT dapat diterapkan dalam bahasa C++ dengan menggunakan `struct` sebagai pembentuk tipe data serta fungsi dan prosedur sebagai operasi untuk mengolah data. Implementasi ADT juga dapat dipisahkan ke dalam beberapa file agar program lebih terorganisir.

#### 1. Struct sebagai Tipe Data

#### 2. Fungsi dan Prosedur sebagai Primitif

#### 3. Pemisahan File `.h` dan `.cpp`

### C. Penerapan ADT pada Program

Penerapan ADT dapat digunakan untuk membuat program yang mengelola data tertentu. Salah satu contoh pada modul adalah ADT mahasiswa yang memiliki data NIM dan nilai serta operasi untuk memasukkan data dan menghitung nilai rata-rata.

#### 1. ADT Mahasiswa

#### 2. Input Data Menggunakan Prosedur

#### 3. Pengolahan Data Menggunakan Fungsi

### D. Array dan Pointer pada Penerapan ADT

## Guided

### 1. buku.h

```C++
#ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;

struct buku{
    string judul;
    int halaman;
    string penulis;
};

void editIsi(string judul, int halaman, string penulis, buku &buku);
void tampilkanisiBuku(buku buku);
bool checkPenulis(buku buku);


#endif
```

File ini berisi deklarasi struct buku yang memiliki data judul, halaman, dan penulis. Selain itu, terdapat deklarasi fungsi editIsi(), tampilkanisiBuku(), dan checkPenulis() yang digunakan untuk mengolah data buku.

### 2. buku.cpp

```C++
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku)
{
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanisiBuku(buku buku)
{
    cout << "Judul Buku : " << buku.judul << endl;
    cout << "Halaman Buku : " << buku.halaman << endl;
    cout << "Penulis Buku : " << buku.penulis << endl;
}

bool checkPenulis(buku buku)
{
    return buku.penulis == "";
}
```

Berisi implementasi dari fungsi-fungsi yang sudah dideklarasikan di buku.h. editIsi() digunakan untuk mengisi data buku, tampilkanisiBuku() untuk menampilkan data, dan checkPenulis() untuk mengecek apakah penulis masih kosong.

### 3. main.cpp

```C++
#include <iostream>
#include "buku.h"

using namespace std;
int main()
{
    buku novel;
    string judul, penulis;
    int halaman;

    cout << "Masukkan Judul Buku : ";
    cin >> judul;
    cout << "Masukkan Halaman Buku : ";
    cin >> halaman;
    cout << "Masukkan Penulis Buku : ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanisiBuku(novel);

    cout << checkPenulis(novel);

    return 0;
}
```

Merupakan program utama yang meminta pengguna memasukkan judul, jumlah halaman, dan penulis buku. Data tersebut kemudian dimasukkan ke novel, ditampilkan menggunakan fungsi, lalu dilakukan pengecekan pada data penulis.

## Unguided

### 1. (Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts+0.4 * uas+0.3 * tugas).

```C++
//mahasiswa.cpp
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
```
```C++
//mahasiswa.h
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
```
```C++
//main.cpp
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul3/output/outputM3-soal1.png)

Program menggunakan struct Mahasiswa untuk menyimpan data mahasiswa dan array untuk menampung maksimal 10 mahasiswa. Fungsi hitungNilaiAkhir() menghitung nilai akhir berdasarkan rumus pada soal, sedangkan inputMahasiswa() digunakan untuk memasukkan data dan tampilMahasiswa() untuk menampilkan hasilnya.

### 2. (Soal meminta ADT pelajaran yang memiliki namaMapel dan kodeMapel, lalu fungsi untuk membuat data pelajaran dan prosedur untuk menampilkannya).

```C++
//pelajaran.cpp
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;

    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
```C++
//pelajaran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
```C++
//main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul3/output/outputM3-soal2.png)

rogram menggunakan struct pelajaran untuk menyimpan nama dan kode mata pelajaran. Fungsi create_pelajaran() mengisi data tersebut, kemudian prosedur tampil_pelajaran() menampilkan hasilnya. Pemisahan file mengikuti konsep ADT pada modul.

### 3. (Soal meminta dua array integer berukuran 3×3, dua pointer integer, prosedur untuk menampilkan array, prosedur untuk menukar dua elemen array pada posisi tertentu, serta prosedur untuk menukar nilai yang ditunjuk oleh dua pointer).

```C++
//pelajaran.cpp
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
```
```C++
//pelajaran.h
#ifndef ARRAY_H
#define ARRAY_H

void tampilArray(int arr[3][3]);
void tukarArray(int arr1[3][3], int arr2[3][3],
                int baris, int kolom);
void tukarPointer(int *p1, int *p2);

#endif
```
```C++
//main.cpp
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul3/output/outputM3-soal3.png)

Program menggunakan dua array 3×3 dan dua pointer integer. Fungsi tampilArray() menampilkan isi array, sedangkan tukarArray() menukar elemen pada posisi yang sama, yaitu baris 2 kolom 2 (indeks [1][1]). Fungsi tukarPointer() menukar nilai yang ditunjuk oleh kedua pointer menggunakan variabel sementara. Disclaimer = Pada soal nomor 3, indeks array di C++ dimulai dari 0. Jadi, posisi [1][1] adalah baris kedua dan kolom kedua. Pointer p1 dan p2 pada contoh menunjuk ke elemen pertama masing-masing array.

## Kesimpulan

Berdasarkan praktikum Modul 3, dapat disimpulkan bahwa Abstract Data Type (ADT) membantu membuat program C++ menjadi lebih terstruktur dengan memisahkan tipe data, fungsi, prosedur, dan program utama ke dalam beberapa file. Melalui praktikum ini, dipelajari penggunaan `struct` untuk menyimpan data, fungsi untuk melakukan perhitungan, serta prosedur untuk memasukkan dan menampilkan data. Selain itu, penggunaan array dan pointer juga membantu dalam mengelola banyak data dan menukar nilai. Dengan memahami konsep ADT, program menjadi lebih rapi, mudah dipahami, dan lebih mudah dikembangkan sesuai kebutuhan.

## Referensi

<br>[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara Medan. https://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf

<br>[2] Budiman, & Alamsyah, N. (2023). Buku Ajar Struktur Data dan Pemrograman. Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/528/.

<br>[3] Budiman, Alamsyah, N., & Rasyid, A. (2023). Buku Ajar Pemrograman C++. Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/531/.

<br>[4] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.