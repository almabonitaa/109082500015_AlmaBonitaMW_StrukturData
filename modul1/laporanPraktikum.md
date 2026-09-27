# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Alma Bonita Mia Wardhana - 109082500015</p>

## Dasar Teori

Code::Blocks merupakan Integrated Development Environment (IDE) gratis dan open-source yang berorientasi pada bahasa C, C++, dan Fortran, di mana bahasa C++ sendiri dikembangkan oleh Bjarne Stroustrup pada awal tahun 1980-an sebagai perluasan dari bahasa C. Secara struktur, program C++ terdiri atas pendeklarasian pustaka (seperti <iostream>), fungsi, serta fungsi utama main() yang didukung oleh penggunaan identifier, tipe data dasar, berbagai jenis operator aritmatika maupun logika, perintah input/output (cin/cout), struktur kondisional (if-else, switch), perulangan (looping), hingga tipe data bentukan (struct) untuk membangun program yang terstruktur.

### A. Code::Blocks dan Struktur Dasar C++<br/>

Pengenalan perangkat lunak Code::Blocks sebagai IDE untuk C/C++ serta kerangka dasar penulisan program menggunakan pustaka standar, fungsi utama main(), serta aturan penulisan sintaks dasar.

#### 1. Pengoperasian IDE

#### 2. Tipe Data dan Variabel

#### 3. Input dan Output

### B. Kontrol Alur, Operator, dan Modularisasi Program<br/>

Logika pemrograman lanjutan untuk mengelola alur eksekusi data, perhitungan, serta pengorganisasian kode yang kompleks.   

#### 1. Operator

#### 2. Kondisional dan Perulangan

#### 3. Struktur (Struct) dan Fungsi

## Guided

### 1. Operasi Aritmatika Dasar

```C++
#include<iostream>
using namespace std;
int main(){
    int w, x, y; float z;
    x = 7; y = 3; w = 1;
    z = (x + y)/(y + w);
    cout << "nilai z = "<< z << endl;
    return 0;
}
```

Program ini digunakan untuk melakukan operasi aritmatika dasar dengan melibatkan variabel integer dan float, di mana hasilnya dikalkulasikan menggunakan tanda kurung sebagai prioritas operator.

### 2. Operator Increment (Pre-Increment)

```C++
#include <iostream>
using namespace std;
int main(){
    int r = 10;
    int s;
    s=10 + ++r;
    cout<< "Nilai r= "<<r<<endl;
    cout<< "Nilai s= "<<s<<endl;
    return 0;
}
```

Kode di atas menerapkan pre-increment (++r), di mana nilai variabel r ditambahkan 1 terlebih dahulu sebelum dijumlahkan dengan angka 10 dan dimasukkan ke variabel s.

### 3. Percabangan Kondisional (if-else)

```C++
#include <iostream>
using namespace std;
int main(){
    double tot_pembelian, diskon;
    cout << " total pembelian : Rp";
    cin >> tot_pembelian;
    diskon = 0;
    if (tot_pembelian >= 100000)
        diskon = 0.05 * tot_pembelian;
    else
        diskon = 0;
    cout << "besar diskon = Rp"<<diskon;
}
```

Program ini memanfaatkan struktur percabangan if-else untuk menyeleksi besaran diskon belanja berdasarkan syarat total pembelian minimal Rp100.000.

### 4. Percabangan Banyak Alternatif (switch-case)

```C++
#include <iostream>
using namespace std;
int main(){
    int kode_hari;
    puts("Menentukan hari kerja/libur\n");
    puts("1=senin 3=rabu 5=jumat 7=minggu ");
    puts("2=selasa 4=kamis 6=sabtu ");
    cin >> kode_hari;
    switch (kode_hari){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << ("Hari kerja");
            break;
        case 6:
        case 7:
            cout << ("Hari libur");
            break;
        default :
            cout << ("code masukan salah") << endl;
    }
    return 0;
}
```

Implementasi switch-case ini digunakan untuk menentukan status hari (kerja atau libur) secara efisien berdasarkan kode angka yang diinputkan pengguna.

### 5. Perulangan do-while

```C++
#include <iostream>
using namespace std;
int main(){
    int i = 1;
    int jum;
    cout<<"masukan banyak baris: ";
    cin>>jum;
    do{
        cout << "baris ke-"<< (i+1)<<endl;
        i++;
    } while (i < jum);
    return 0;
}
```

Kode tersebut menjalankan perulangan dengan struktur do-while, yang memastikan blok kode di dalamnya dieksekusi setidaknya satu kali sebelum pengecekan kondisi di akhir.

### 6. Perulangan while

```C++
#include <iostream>
using namespace std;
int main(){
    int i = 1;
    int jum;
    cout<<"masukan banyak baris: ";
    cin>>jum;
    while(i <= jum){
        cout << "baris ke-"<< i << endl;
        i++;
    }
    return 0;
}
```

Contoh ini menggunakan perulangan while untuk mencetak baris teks secara berulang selama nilai penghitung isi masih kurang dari atau sama dengan jumlah inputan.

### 7. Perulangan for

```C++
#include <iostream>
using namespace std;
int main(){
    int jum;
    cout << "jumlah perulangan: ";
    cin >> jum;
    for(int i = 0; i < jum; i++){
        cout << "saya pintar\n";
    }
    return 0;
}
```

Program ini menerapkan perulangan for yang sangat ideal digunakan ketika jumlah iterasi atau perulangannya sudah diketahui secara pasti sejak awal.

### 8. Array dan Struktur (Struct)

```C++
#include <iostream>
#define MAX 5
using namespace std;
int main(){
    int i;
    struct data{
        char nama[40];
        int nilai;
    };
    data siswa[MAX];
    for (i = 0; i < MAX; i++){
        cout << "masukkan data ke-"<<i+1<<endl;
        cout << "nama = ";
        cin >> siswa[i].nama;
        cout << "nilai = ";
        cin >> siswa[i].nilai;
    }
    cout << "\ndata siswa\n";
    cout << "=======";
    for (i = 0; i < MAX; i++){
        cout << "\n \ndata ke-"<<i+1;
        cout << "\n \nnama = "<<siswa[i].nama;
        cout << "\n \nnilai = "<<siswa[i].nilai;
    }
    return 0;
}
```

Kode di atas menggabungkan tipe data bentukan struct dan array untuk menyimpan kumpulan data mahasiswa yang terdiri dari atribut nama dan nilai secara terstruktur.

### 9. Modularisasi Program dengan Fungsi

```C++
#include <iostream>
using namespace std;

float ctof(float celcius);
int main() {
    float celcius, fahrenheit;
    cout <<"nilai Celcius? ";
    cin >> celcius;
    fahrenheit = ctof(celcius);
    cout<<celcius<<" Celcius adalah "<<fahrenheit<<" Fahrenheit"<<endl;
    return 0;
}

float ctof(float celcius){
    return (celcius * 1.8) + 32;
}
```

Program ini mengimplementasikan fungsi buatan user-defined function ctof untuk memisahkan logika perhitungan konversi suhu dari Celcius ke Fahrenheit agar kode utama lebih rapi dan modular.


## Unguided

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan

...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...