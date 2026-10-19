# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>

<p align="center">Alma Bonita Mia Wardhana - 109082500015</p>

## Dasar Teori

Pada modul ini dibahas konsep Singly Linked List yang merupakan salah satu bentuk struktur data untuk menyimpan sekumpulan elemen yang saling terhubung menggunakan pointer. Struktur data ini bersifat fleksibel karena jumlah elemennya dapat bertambah atau berkurang sesuai kebutuhan. Dalam bahasa C++, Singly Linked List dapat diterapkan menggunakan struct, pointer, dan beberapa operasi dasar untuk mengelola data.

### A. Konsep Linked List

Linked List merupakan struktur data yang terdiri dari elemen-elemen yang saling terhubung. Setiap elemen menyimpan data dan alamat elemen berikutnya. Linked List menggunakan pointer agar hubungan antar elemen dapat diatur sesuai kebutuhan.

### B. Implementasi Singly Linked List

Singly Linked List dapat diterapkan dalam C++ menggunakan struct untuk membentuk elemen list dan pointer untuk menghubungkan setiap elemen. Implementasinya juga melibatkan pengelolaan memori agar elemen dapat dibuat dan dihapus sesuai kebutuhan.

### C. Operasi Dasar Singly Linked List

Operasi dasar Singly Linked List digunakan untuk mengelola elemen yang terdapat dalam list. Operasi tersebut meliputi pembuatan list, penyisipan data, penghapusan data, dan penelusuran elemen untuk menampilkan informasi yang tersimpan.

### D. Penerapan ADT Singly Linked List pada Program

ADT Singly Linked List diterapkan dengan memisahkan deklarasi tipe data dan prototipe fungsi ke dalam file .h, sedangkan implementasi operasi disimpan dalam file .cpp. Program utama kemudian menggunakan operasi tersebut untuk membuat list, menambahkan elemen, menampilkan data, dan melakukan pengelolaan elemen lainnya.

## Guided

### 1. list.h

```C++
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty (linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list,address nodeBaru);
void insertAfter(linkedlist &list,address nodeBaru, address prev);
void insertLast(linkedlist &list,address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);
#endif
```

File list.h berisi deklarasi struktur data dan prototipe fungsi yang digunakan dalam program Singly Linked List. Pada file ini, struct mahasiswa digunakan untuk menyimpan nama, NIM, dan umur mahasiswa, sedangkan struct node digunakan untuk menghubungkan data mahasiswa dengan pointer next. Selain itu, terdapat struct linkedlist yang memiliki pointer first sebagai penunjuk node pertama, serta deklarasi fungsi untuk menambah, menghapus, menampilkan, dan menghitung jumlah node.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &List)
{
    {
        /* I.S. sembarang
        F.S. terbentuk list kosong */
        List.first = Nil;
    }
}

address alokasi(string nama, string nim, int umur)
{
    {
        /* I.S. sembarang
        F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
        address nodeBaru = new node;
        nodeBaru->isidata.nama = nama;
        nodeBaru->isidata.nim = nim;
        nodeBaru->isidata.umur = umur;
        nodeBaru->next = Nil;
        return nodeBaru;
    }
}

void dealokasi(address &node)
{
        /* I.S. P terdefinisi
        F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next !=Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
```

File list.cpp berisi implementasi fungsi-fungsi yang telah dideklarasikan pada list.h. Fungsi isEmpty() digunakan untuk mengecek apakah list kosong, createList() untuk membuat list kosong, dan alokasi() untuk membuat node baru yang berisi data mahasiswa. Fungsi dealokasi() digunakan untuk membebaskan memori, sedangkan insertFirst(), insertAfter(), dan insertLast() digunakan untuk menambahkan node. Selain itu, terdapat fungsi delFirst(), delLast(), dan delAfter() untuk menghapus node, printList() untuk menampilkan data mahasiswa, nbList() untuk menghitung jumlah node, serta deleteList() untuk menghapus seluruh node dalam list.

### 3. main.cpp

```C++
#include "list.h"
using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
}
```

File main.cpp merupakan program utama yang digunakan untuk menjalankan dan menguji operasi Singly Linked List. Program diawali dengan membuat list kosong, kemudian membuat lima node yang berisi data mahasiswa Dhimas, Arvin, Rizal, Satrio, dan Joshua. Selanjutnya, data dimasukkan menggunakan fungsi insertFirst(), insertLast(), dan insertAfter(). Setelah semua data dimasukkan, fungsi printList() digunakan untuk menampilkan seluruh data mahasiswa dan nbList() untuk menghitung jumlah node. Terakhir, fungsi delFirst() dipanggil untuk menghapus node pertama dari list.

## Unguided

### 1. (implementasi ADT Singly Linked List menggunakan pointer dalam C++).

```C++
//singlylist.cpp
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```
```C++
//singlylist.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif 
```
```C++
//main.cpp
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul4/output/output-soal1.png)

program ini menerapkan konsep Singly Linked List menggunakan pointer dalam C++. Program membuat list kosong, mengalokasikan memori untuk setiap node, lalu memasukkan lima angka, yaitu 2, 0, 8, 12, dan 9 ke awal list. Data kemudian ditampilkan secara berurutan menjadi 9 12 8 0 2 karena setiap node baru ditambahkan di bagian awal list.

## Kesimpulan

Berdasarkan praktikum Modul 4, dapat disimpulkan bahwa Singly Linked List adalah struktur data yang terdiri dari beberapa node yang saling terhubung menggunakan pointer. Berbeda dengan array, Singly Linked List dapat menambah atau menghapus data dengan lebih fleksibel sesuai kebutuhan program.

Selain itu, penggunaan konsep Abstract Data Type (ADT) membuat program lebih rapi dan mudah dipahami karena kode dibagi menjadi tiga file. File .h digunakan untuk mendeklarasikan struktur data dan fungsi, file .cpp berisi kode untuk menjalankan fungsi, sedangkan main.cpp digunakan sebagai program utama. Dengan memahami Singly Linked List, kita dapat mengelola dan mengatur data dengan lebih terstruktur melalui operasi seperti menambah, menghapus, dan menampilkan data.

## Referensi

<br>[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara Medan. https://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf

<br>[2] Budiman, & Alamsyah, N. (2023). Buku Ajar Struktur Data dan Pemrograman. Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/528/.

<br>[3] Budiman, Alamsyah, N., & Rasyid, A. (2023). Buku Ajar Pemrograman C++. Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/531/.

<br>[4] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.