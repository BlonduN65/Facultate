#ifndef HEDER_H
#define HEDER_H

#define DIMMAX 100


void INSERT(int A[], int &N, int X);
int REMOVE(int A[], int &N);

void RETRO(int A[], int N, int i) ;
int REMOVE2(int A[], int &N);

void BuildHeap_V1(int A[], int N);
void BuildHeap_V2(int A[], int N) ;

void AFISARE(int A[], int N);
void HeapSort(int A[], int N);

#endif