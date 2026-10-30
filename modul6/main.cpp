#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    infotype data;
    string inputNopol;
    address P;
    
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;
        
        if (findElm(L, data.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar\n\n";
        } else {
            P = alokasi(data);
            insertFirst(L, P); 
            cout << endl;
        }
    }
    
    printInfo(L);
    cout << "--------------------------------\n";

    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> inputNopol;
    address found = findElm(L, inputNopol);
    if (found != Nil) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << "--------------------------------\n";

    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> inputNopol;
    address delTarget = findElm(L, inputNopol);
    
    if (delTarget != Nil) {
        if (delTarget == L.First) {
            deleteFirst(L, P);
        } else if (delTarget == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = delTarget->prev;
            deleteAfter(Prec, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << inputNopol << " berhasil dihapus.\n\n";
    } else {
        cout << "Data tidak ditemukan.\n\n";
    }

    printInfo(L);

    return 0;
}