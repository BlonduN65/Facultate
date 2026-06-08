#include "header.h"
#include <algorithm>
#include <iostream> 
using namespace std;
void INSERT(int A[], int &N, int X) {
    
    N = N + 1;      
    A[N] = X;       
    
    int fiu = N;
    int parinte = fiu / 2;

    while (parinte >= 1) {
        if (A[parinte] < A[fiu]) {
         
            swap(A[parinte], A[fiu]);
            fiu = parinte;
            parinte = fiu / 2;
        
        } 
        else 
        {
            break; 
        }
    }
}

int REMOVE(int A[], int &N) {
    
    if (N == 0) 
        return -1; 

    int radacina = A[1];   
    A[1] = A[N];           
    N = N - 1;             

    int parinte = 1;
    int fiu = 2; 

    
    while (fiu <= N) {
        
        if (fiu + 1 <= N && A[fiu] < A[fiu + 1]) {
        
            fiu = fiu + 1;
        
        }

       
        if (A[fiu] > A[parinte]) {
        
            swap(A[parinte], A[fiu]);
            parinte = fiu;
            fiu = parinte * 2;
        
        } 
        else 
        {
            break; 
        }
    }

    return radacina;
}
void RETRO(int A[], int N, int i) {
    int p = i;
    int f = 2 * i;
    while(f <= N) {
        if(f+1 <= N && A[f] < A[f+1]) 
            f++;
        if(A[f] > A[p]) 
        { 
            swap(A[p], A[f]); 
            p = f; 
            f = p*2; 
        }
        else break;
    }
}

int REMOVE2(int A[], int &N) {
    int rad = A[1];
    A[1] = A[N]; N--;
    RETRO(A, N, 1); 
    return rad;
}

void BuildHeap_V2(int A[], int N) {
    for (int i = N / 2; i >= 1; i--) {
        RETRO(A, N, i);
    }
}
void HeapSort(int A[], int N) {
    
    for (int i = N / 2; i >= 1; i--) {
        RETRO(A, N, i);
    }

    
    for (int i = N; i > 1; i--) {
        swap(A[1], A[i]); 
        RETRO(A, i - 1, 1); 
    }

}
void AFISARE(int A[], int N) {
    for (int i = 1; i <= N; i++) 
        cout << A[i] << " ";
    cout << endl;
}
void BuildHeap_V1(int A[], int N) {
    for (int i = 2; i <= N; i++) {
        int fiu = i;
        int parinte = fiu / 2;
        

        while (parinte >= 1 && A[parinte] < A[fiu]) {
            swap(A[parinte], A[fiu]);
            fiu = parinte;
            parinte = fiu / 2;
        }
    }
}

