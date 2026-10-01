#include "header.h"

int main() {
    lista* cap = NULL;
    int heap[100], n_heap = 0;

    cout << "Dati valori (0 pentru oprire): ";
    creare_lista(cap);

    cout << "Lista circulara: ";
    afisare(cap);

    valori_pare(cap);

    // 1. Identificarea nodurilor pare și crearea MinHeap
    creare_heap_din_lista(cap, heap, n_heap);

    cout << "MinHeap-ul ca vector: ";
    afisare_heap(heap, n_heap);

    // 2. Ordonarea descrescătoare
    heap_sort_descrescator(heap, n_heap);

    cout << "MinHeap sortat descrescator: ";
    afisare_heap(heap, n_heap);

    return 0;
}