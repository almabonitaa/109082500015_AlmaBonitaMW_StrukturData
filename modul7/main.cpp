#include <iostream>
#include "stack.h"

using namespace std;

// ==========================================
// LATIHAN 1: Implementasi Dasar & balikStack
// ==========================================
// int main() {
//     cout << "Hello world!" << endl;
//     Stack S;
//     createStack(S);
    
//     push(S, 3);
//     push(S, 4);
//     push(S, 8);
//     pop(S);
//     push(S, 2);
//     push(S, 3);
//     pop(S);
//     push(S, 9);
    
//     printInfo(S);
//     cout << "balik stack" << endl;
//     balikStack(S);
//     printInfo(S);
    
//     return 0;
// }

// ==========================================
// LATIHAN 2: pushAscending
// ==========================================

// int main() {
//     cout << "Hello world!" << endl;
//     Stack S;
//     createStack(S);
    
//     pushAscending(S, 3);
//     pushAscending(S, 4);
//     pushAscending(S, 8);
//     pushAscending(S, 2);
//     pushAscending(S, 3);
//     pushAscending(S, 9);
    
//     printInfo(S);
//     cout << "balik stack" << endl;
//     balikStack(S);
//     printInfo(S);
    
//     return 0;
// }

// ==========================================
// LATIHAN 3: getInputStream
// ==========================================

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    
    getInputStream(S); // Masukkan input secara berderet, contoh: 4729601
    
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}