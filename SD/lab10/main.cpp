#include <iostream>
#include "header.h"

using namespace std;

int main() {
    int A[DIMMAX + 1];
    int N = 0;

    
    int date[] = {12, 45, 20, 30, 7, 1, 22};
    int nr = sizeof(date) / sizeof(date[0]);

    cout << "Se insereaza elementele in heap" << endl;
    for (int i = 0; i < nr; i++) {
        INSERT(A, N, date[i]);
    }

    /*cout << "Elementele extrase din heap (ordine descrescatoare):" << endl;
    while (N > 0) {
        cout << REMOVE(A, N) << " ";
    }
    cout << endl;*/
    
    cout << "Inainte de sortare: ";
    AFISARE(A, N);

    HeapSort(A, N);

    cout << "Dupa HeapSort:     ";
    AFISARE(A, N);

    return 0;
}