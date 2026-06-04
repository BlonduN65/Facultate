#ifndef HEADER_H
#define HEADER_H

struct NodDistanta{

    int id;
    unsigned int distanta;
};

void algoritmDijkstra(int **graf, int n, int start , unsigned int *dist, int *previous);
void afisareDrumMinim(int start, int destinatie, unsigned int *dist, int *previous);
void pushHeap(NodDistanta *heap, int &heapsize, NodDistanta nod);
NodDistanta popHeap(NodDistanta *heap, int &heapsize);



#endif 