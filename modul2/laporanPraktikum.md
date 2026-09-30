# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>

<p align="center">Alma Bonita Mia Wardhana - 109082500015</p>

## Dasar Teori

Pada modul ini dibahas beberapa konsep dasar dalam bahasa C++ yang berkaitan dengan pengolahan data dan pembuatan program. Materinya meliputi array, pointer, string, fungsi, prosedur, serta cara mengirimkan parameter ke dalam fungsi. Konsep-konsep tersebut digunakan agar program dapat mengelola data dengan lebih baik dan memiliki struktur yang lebih jelas.

### A. Array dan Pointer<br/>

Membahas cara menyimpan dan mengakses kumpulan data menggunakan array serta memahami pointer yang digunakan untuk menyimpan alamat memori suatu variabel.

#### 1. Array Satu Dimensi

#### 2. Array Dua Dimensi dan Berdimensi Banyak

#### 3. Pointer dan Alamat Memori

#### 4. Pointer dengan Array dan String

### B. Fungsi dan Prosedur<br/>

Membahas cara membagi program menjadi beberapa bagian menggunakan fungsi dan prosedur agar program lebih terstruktur dan tidak banyak melakukan penulisan kode yang sama.

#### 1. Fungsi

#### 2. Prosedur

### C. Parameter Fungsi<br/>

Membahas cara memasukkan data ke dalam fungsi melalui parameter. Parameter dapat dikirim menggunakan nilai, pointer, maupun referensi, yang masing-masing memiliki cara kerja berbeda.

#### 1. Parameter Formal dan Aktual

#### 2. Call by Value

#### 3. Call by Pointer

#### 4. Call by Reference

## Guided

### 1. Array Satu Dimensi dan Array Dua Dimensi

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    }; 
    /* inisialisasi array dua dimensi */
    for (i=0; i<MAX; i++) {
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    
    cout<<"\ndata nilai siswa :\n";

    /* menampilkan array satu dimensi */
    for (i=0; i<MAX; i++)
        cout<<"nilai k-"<<i+1<<"="<<nilai[i]<<endl;
        
    cout<<"\nnilai tahunan : \n";
    
    /* menampilkan array dua dimensi */
    for (i=0; i<MAX; i++) {
        for (j=0; j<MAX; j++) {
            cout<<nilai_tahun[i][j];
        }
        cout<<"\n";
    }
    
    return 0;
}
```

Program ini digunakan untuk menginput dan menampilkan data menggunakan array satu dimensi dan array dua dimensi. Array satu dimensi nilai[MAX] digunakan untuk menyimpan nilai siswa, sedangkan nilai_tahun[MAX][MAX] digunakan untuk menyimpan dan menampilkan data dalam bentuk tabel.

### 2. Pointer dan Alamat Memori

```C++
#include <iostream>
using namespace std;
int main(){
    int x, y; // x dan y bertipe int
    int *px; // px merupakan variabel pointer menunjuk ke variabel int
    
    x = 87;
    px = &x;
    y = *px;
    
    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;
    
    return 0;
}
```

Program ini digunakan untuk memahami cara kerja pointer dalam menyimpan alamat memori suatu variabel. Pointer px menunjuk ke alamat variabel x, sedangkan *px digunakan untuk mengambil nilai yang ada pada alamat tersebut.

### 3. Fungsi

```C++
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);
int main(){
    int x,y,z;
    cout<<"masukkan nilai bilangan ke-1 = ";
    cin>>x;
    cout<<"masukkan nilai bilangan ke-2 = ";
    cin>>y;
    cout<<"masukkan nilai bilangan ke-3 = ";
    cin>>z;
    cout<<"nilai maksimumnya adalah = " <<maks3(x,y,z);
    return 0;
}
int maks3(int a, int b, int c){
    int temp_max =a;
    if(b>temp_max)
    temp_max=b;
    if(c>temp_max)
    temp_max=c;
    return (temp_max);
}
```

Program ini menggunakan fungsi maks3() untuk mencari nilai terbesar dari tiga bilangan yang dimasukkan oleh pengguna. Fungsi menerima tiga parameter, kemudian membandingkan setiap nilai dan mengembalikan nilai terbesar melalui return.

### 4. Prosedur

```C++
#include <iostream>
using namespace std;

/* Prototype fungsi */
void tulis(int x);

int main() {
    int jum;
    
    cout << "Jumlah baris kata = ";
    cin >> jum;
    
    tulis(jum);
    
    return 0;
}

/* Badan prosedur */
void tulis(int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke-" << i + 1 << endl;
    }
}
```

Program ini menggunakan prosedur tulis() untuk menampilkan nomor baris sesuai dengan jumlah yang dimasukkan pengguna. Prosedur menggunakan void karena tidak mengembalikan nilai, tetapi hanya menjalankan tugas tertentu.

### 5. Parameter Fungsi : Call by Value, Pointer, dan Reference

```C++
#include <iostream>
using namespace std;

// 1. Call by Value: variabel asli TIDAK berubah
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. Call by Pointer: variabel asli IKUT berubah (pakai *)
void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Call by Reference: variabel asli IKUT berubah (pakai &)
void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4, b = 6;

    // Tes Call by Value
    tukarValue(a, b);
    cout << "Setelah Call by Value     -> a = " << a << ", b = " << b << " (Tetap)" << endl;

    // Tes Call by Pointer (kirim alamatnya pakai &)
    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer   -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    // Tes Call by Reference (mengembalikan posisi semula)
    tukarReference(a, b);
    cout << "Setelah Call by Reference -> a = " << a << ", b = " << b << " (Berubah lagi!)" << endl;

    return 0;
}
```

Program ini membandingkan tiga cara pengiriman parameter pada fungsi, yaitu call by value, call by pointer, dan call by reference. Pada call by value, perubahan di dalam fungsi tidak mengubah variabel asli, sedangkan call by pointer dan call by reference dapat mengubah nilai variabel asli.

## Unguided

### 1. (Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.)

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Hasil penjumlahan = " << a + b << endl;
    cout << "Hasil pengurangan = " << a - b << endl;
    cout << "Hasil perkalian = " << a * b << endl;
    cout << "Hasil pembagian = " << a / b << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul1/output/output-soal1.png)

Program ini digunakan untuk menghitung penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan bertipe float.

### 2. (Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100)

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas", "dua belas", "tiga belas",
        "empat belas", "lima belas", "enam belas",
        "tujuh belas", "delapan belas", "sembilan belas"
    };

    if (angka < 20) {
        cout << satuan[angka];
    }
    else if (angka < 100) {
        cout << satuan[angka / 10] << " puluh";

        if (angka % 10 != 0) {
            cout << " " << satuan[angka % 10];
        }
    }
    else if (angka == 100) {
        cout << "seratus";
    }
    else {
        cout << "Angka tidak valid";
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul1/output/output-soal2.png)

Program ini digunakan untuk mengubah angka 0–100 menjadi bentuk tulisan dalam bahasa Indonesia menggunakan percabangan if-else.

### 3. (Buatlah program yang dapat memberikan input dan output sbb.)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {

        for (int spasi = n; spasi > i; spasi--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul1/output/output-soal3.png)

Program ini digunakan untuk menampilkan pola angka berbentuk segitiga terbalik dengan menggunakan perulangan for.

## Kesimpulan

Berdasarkan praktikum Modul 1, dapat disimpulkan bahwa C++ memiliki beberapa dasar penting yang perlu dipahami dalam membuat program, seperti penggunaan variabel dan tipe data, input dan output, operator, percabangan, perulangan, array, struct, serta fungsi. Melalui praktikum ini, saya juga memahami bahwa setiap struktur program memiliki kegunaan yang berbeda, seperti if-else dan switch-case untuk menentukan kondisi, sedangkan for, while, dan do-while digunakan untuk melakukan perulangan. 
Selain itu, penggunaan array, struct, dan fungsi dapat membantu membuat program lebih terstruktur dan mudah dipahami. Dari soal unguided, saya dapat menerapkan materi tersebut untuk membuat program perhitungan aritmatika, mengubah angka menjadi tulisan, serta membuat pola angka menggunakan perulangan. Dengan praktikum ini, pemahaman dasar pemrograman C++ menjadi lebih baik dan dapat menjadi dasar untuk mempelajari materi pemrograman selanjutnya.

## Referensi

<br>[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

<br>[2] Indahyati, U., & Rahmawati, Y. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.

<br>[3] Suryana, T. (2004). *Pemrograman C++ Builder 6*. Bandung: Universitas Komputer Indonesia. Materi ini membahas dasar pemrograman C++.

<br>[4] Nurhayati, S. (2013). *Konsep Dasar Algoritma dan Pemrograman Terstruktur*. Bandung: Universitas Komputer Indonesia. Materi ini membahas konsep dasar algoritma dan pemrograman terstruktur.

<br>[5] Kadir, A. (2017). *Dasar Logika Pemrograman Komputer*. Jakarta: Elex Media Komputindo. Materi ini membahas konsep dasar pemrograman yang berkaitan dengan penggunaan variabel, array, fungsi, dan struktur program.

