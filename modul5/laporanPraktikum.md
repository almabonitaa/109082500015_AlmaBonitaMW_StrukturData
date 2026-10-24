# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA) </h1>

<p align="center">Alma Bonita Mia Wardhana - 109082500015</p>

## Dasar Teori

Pada modul ini dibahas konsep Singly Linked List dan beberapa operasi yang dapat dilakukan pada list. Materi pada modul meliputi proses searching, pembuatan ADT Singly Linked List, serta operasi untuk menambahkan, menghapus, mencari, menampilkan, dan mengelola elemen dalam list. Singly Linked List menggunakan pointer untuk menghubungkan setiap elemen sehingga data dapat dikelola sesuai kebutuhan.

### A. Konsep Searching pada Linked List

Searching merupakan proses untuk mencari elemen tertentu yang terdapat di dalam linked list. Proses pencarian dilakukan dengan mengunjungi setiap node satu per satu sampai data yang dicari ditemukan. Searching juga dapat membantu dalam melakukan operasi lain seperti insert after, delete after, dan update.

### B. Implementasi ADT Singly Linked List

ADT Singly Linked List digunakan untuk mengatur struktur dan operasi yang ada pada linked list. Pada implementasinya terdapat tipe data infotype, address, ElmList, dan List, di mana setiap elemen memiliki data info dan pointer next yang menunjuk ke elemen berikutnya. List memiliki pointer first yang digunakan untuk menunjuk ke elemen pertama.

### C. Operasi Dasar Singly Linked List

Operasi dasar pada Singly Linked List digunakan untuk mengelola data yang ada di dalam list. Beberapa operasi yang digunakan yaitu membuat list kosong, melakukan alokasi dan dealokasi memori, mencari elemen, menambahkan elemen di awal atau akhir list, menghapus elemen, menampilkan seluruh data, menghitung jumlah elemen, serta membalik urutan elemen dalam list.

### D. Penerapan ADT Singly Linked List pada Program

ADT Singly Linked List diterapkan dengan membuat deklarasi struktur data dan prototype fungsi pada file Singlylist.h, kemudian implementasi fungsi dibuat pada file Singlylist.cpp. Program utama pada main.cpp digunakan untuk membuat list, melakukan alokasi data, menambahkan beberapa elemen menggunakan insertFirst, dan menampilkan isi list menggunakan printInfo. Pada latihan modul, data yang dimasukkan adalah 2, 0, 8, 12, dan 9.

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

File `list.h` digunakan untuk mendefinisikan struktur data dan prototype fungsi yang diperlukan dalam Singly Linked List. Di dalamnya terdapat struktur data mahasiswa, node, linked list, serta fungsi untuk insert, delete, searching, update, dan pengelolaan list.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
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

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
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

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
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

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
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
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    address nodeBantu = list.first;
    while (nodeBantu->next != Nil)
    {
        nodeBantu = nodeBantu->next;
    }

    nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedlist list,address &prev)
{
   if (isEmpty(list))
   {
     cout << "List kosong!" << endl;
   }
   else
   {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
   }
}


void updateByNim(linkedlist &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = findNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}


// prosedur-prosedur untuk searching data didalam list
address findNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur >= nilaiAwal && umur <= nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

Program ini digunakan untuk mengimplementasikan fungsi-fungsi Singly Linked List yang sudah dideklarasikan pada `list.h`. Program mencakup proses pembuatan node, insert, delete, menampilkan dan menghitung node, searching data, serta update data mahasiswa.

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

    updateFirst(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    printList(List);

    updateLast(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    printList(List);

    updateAfter(List, nodeA);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER NODE A ---" << endl;
    printList(List);

    updateByNim(List, "221110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);

    return 0;
}
```

Program ini digunakan untuk membuat dan mengelola Singly Linked List yang berisi data mahasiswa. Program melakukan proses insert pada beberapa posisi, menampilkan isi dan jumlah node, serta melakukan update data pada node pertama, terakhir, setelah node tertentu, dan berdasarkan NIM.

## Unguided

### 1. Implementasi Searching pada Singly Linked List.

```C++
//singlylist.cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

address findElm(List L, infotype x) {
    address P = L.First;

    while (P != nullptr) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

int totalInfo(List L) {
    address P = L.First;
    int total = 0;

    while (P != nullptr) {
        total = total + P->info;
        P = P->next;
    }

    return total;
}
```
```C++
//singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
```
```C++
//main.cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

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

    cout << "Isi linked list: ";
    printInfo(L);

    address P = findElm(L, 8);

    if (P != nullptr) {
        cout << P->info << " ditemukan dalam list" << endl;
    } else {
        cout << "Data tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah "
         << totalInfo(L) << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/almabonitaa/109082500015_AlmaBonitaMW_StrukturData/blob/main/modul5/output/output-soal1.png)

Program ini menggunakan struktur data Singly Linked List untuk menyimpan beberapa nilai, yaitu 9, 12, 8, 0, dan 2. Fungsi insertFirst() digunakan untuk menambahkan elemen di bagian awal list, sedangkan printInfo() menampilkan seluruh elemen. Fungsi findElm() digunakan untuk mencari nilai 8 dengan memeriksa elemen satu per satu. Terakhir, fungsi totalInfo() menjumlahkan seluruh nilai elemen sehingga diperoleh hasil 31.

## Kesimpulan

Berdasarkan praktikum Modul 5, dapat disimpulkan bahwa Singly Linked List dapat digunakan untuk menyimpan dan mengelola data dengan bantuan pointer. Pada praktikum ini dipelajari operasi seperti insert, delete, searching, dan update serta penerapan ADT menggunakan file `.h`, `.cpp`, dan `main.cpp`.

## Referensi

<br>[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara Medan. https://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf

<br>[2] Budiman, & Alamsyah, N. (2023). Buku Ajar Struktur Data dan Pemrograman. Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/528/.

<br>[3] Budiman, Alamsyah, N., & Rasyid, A. (2023). Buku Ajar Pemrograman C++. Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/531/.

<br>[4] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.