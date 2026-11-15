#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.top = -1; // Index -1 digunakan untuk merepresentasikan stack kosong dalam array C++
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype temp = 0;
    if (S.top != -1) {
        temp = S.info[S.top];
        S.top--;
    }
    return temp;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    while (S.top != -1) {
        push(temp1, pop(S));
    }
    while (temp1.top != -1) {
        push(temp2, pop(temp1));
    }
    while (temp2.top != -1) {
        push(S, pop(temp2));
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    
    push(S, x);
    
    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char c;
    while ((c = cin.get()) != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0'); 
        }
    }
}