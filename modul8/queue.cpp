// #include "queue.h"
// #include <iostream>
// using namespace std;

// void createQueue(Queue &Q) {
//     Q.head = -1;
//     Q.tail = -1;
// }

// bool isEmptyQueue(const Queue &Q) {
//     return Q.head == -1;
// }

// bool isFullQueue(const Queue &Q) {
//     return Q.tail == MAX_QUEUE - 1;
// }

// void enqueue(Queue &Q, infotype x) {
//     if (isFullQueue(Q)) {
//         cout << "Queue penuh" << endl;
//         return;
//     }

//     if (isEmptyQueue(Q)) {
//         Q.head = 0;
//     }

//     Q.tail++;
//     Q.info[Q.tail] = x;
// }

// infotype dequeue(Queue &Q) {
//     if (isEmptyQueue(Q)) {
//         cout << "Queue kosong" << endl;
//         return -1;
//     }

//     infotype x = Q.info[Q.head];

//     for (int i = Q.head; i < Q.tail; i++) {
//         Q.info[i] = Q.info[i + 1];
//     }

//     Q.tail--;

//     if (Q.tail < Q.head) {
//         Q.head = -1;
//         Q.tail = -1;
//     }

//     return x;
// }

// void printInfo(const Queue &Q) {
//     cout << Q.head << " - " << Q.tail << " | ";

//     if (isEmptyQueue(Q)) {
//         cout << "empty queue";
//     } else {
//         for (int i = Q.head; i <= Q.tail; i++) {
//             cout << Q.info[i] << " ";
//         }
//     }

//     cout << endl;
// }


//ALTERNATIF 2
// #include "queue.h"
// #include <iostream>
// using namespace std;

// void createQueue(Queue &Q) {
//     Q.head = -1;
//     Q.tail = -1;
// }

// bool isEmptyQueue(const Queue &Q) {
//     return Q.head == -1;
// }

// bool isFullQueue(const Queue &Q) {
//     if (isEmptyQueue(Q)) {
//         return false;
//     }

//     return (Q.tail - Q.head + 1) == MAX_QUEUE;
// }

// void enqueue(Queue &Q, infotype x) {
//     if (isFullQueue(Q)) {
//         cout << "Queue penuh" << endl;
//         return;
//     }

//     if (isEmptyQueue(Q)) {
//         Q.head = 0;
//         Q.tail = 0;
//     } else {
//         if (Q.tail == MAX_QUEUE - 1) {
//             int jumlah = 0;

//             for (int i = Q.head; i <= Q.tail; i++) {
//                 Q.info[jumlah] = Q.info[i];
//                 jumlah++;
//             }

//             Q.head = 0;
//             Q.tail = jumlah - 1;
//         }

//         Q.tail++;
//     }

//     Q.info[Q.tail] = x;
// }

// infotype dequeue(Queue &Q) {
//     if (isEmptyQueue(Q)) {
//         cout << "Queue kosong" << endl;
//         return -1;
//     }

//     infotype x = Q.info[Q.head];

//     if (Q.head == Q.tail) {
//         Q.head = -1;
//         Q.tail = -1;
//     } else {
//         Q.head++;
//     }

//     return x;
// }

// void printInfo(const Queue &Q) {
//     cout << Q.head << " - " << Q.tail << " | ";

//     if (isEmptyQueue(Q)) {
//         cout << "empty queue";
//     } else {
//         for (int i = Q.head; i <= Q.tail; i++) {
//             cout << Q.info[i] << " ";
//         }
//     }

//     cout << endl;
// }


//ALTERNATIF 3
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return Q.head == -1;
}

bool isFullQueue(const Queue &Q) {
    if (isEmptyQueue(Q)) {
        return false;
    }

    return (Q.tail + 1) % MAX_QUEUE == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }

    return x;
}

void printInfo(const Queue &Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;

        while (true) {
            cout << Q.info[i] << " ";

            if (i == Q.tail) {
                break;
            }

            i = (i + 1) % MAX_QUEUE;
        }
    }

    cout << endl;
}