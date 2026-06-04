#include "header.h"
#include <iostream>
using namespace std;
#include <limits>

void pushHeap(NodDistanta *heap, int &heapsize, NodDistanta nod){

        int i = heapsize++;
        while(i>0){
            int p=(i-1)/2;
            if(heap[p].distanta<=nod.distanta) 
                break;
            heap[i]=heap[p];
            i=p;
        }
        
        heap[i]=nod;

}
NodDistanta popHeap(NodDistanta *heap, int &heapsize){
    
        NodDistanta top=heap[0];
        NodDistanta last=heap[--heapsize];
        int i=0;
        while(i*2+1<heapsize){
            int copil=i*2+1;
            if(copil+1<heapsize && heap[copil+1].distanta<heap[copil].distanta)
                copil++;
            if(last.distanta<=heap[copil].distanta)
                break;
            heap[i]=heap[copil];
            i=copil;
        }

        heap[i]=last;
        return top;

}
void algoritmDijkstra(int **graf, int n, int start , unsigned int *dist, int *previous){

    unsigned int uimax=numeric_limits<unsigned int>::max();
    NodDistanta *heaplocal=new NodDistanta[n*n];
    int currentHeapSize=0;

    for(int v=0;v<n;v++){
        dist[v]=uimax;
        previous[v]=-1;
    }
    dist[start]=0;
    pushHeap(heaplocal,currentHeapSize,{start,0});

    while(currentHeapSize>0){
        NodDistanta curent=popHeap(heaplocal,currentHeapSize);
        int u=curent.id;
        if(curent.distanta>dist[u])
            continue;

        for(int v=0;v<n;v++){
            if(graf[u][v]>0){
                
                unsigned int alt= dist[u]+graf[u][v];
                if(alt<dist[v]){
                  
                    dist[v]=alt;
                    previous[v]=u;
                    pushHeap(heaplocal,currentHeapSize,{v,alt});
                
                }
    
          }

        }
    }

delete[] heaplocal;
}

void afisareDrumMinim(int start, int destinatie, unsigned int *dist, int *previous){

    unsigned int uimax=numeric_limits<unsigned int>::max();
    if(dist[destinatie]==uimax){
        cout<<"Nu exista drum de la "<<start<<" la "<<destinatie<<endl;
        return;
    }
    int *stiva =new int[destinatie+100];
    int top=-1;
    int u=destinatie;
    while(u!=-1){
        stiva[++top]=u;
        u=previous[u];
    }

    cout<<"Drumul minim de la "<<start<<" la "<<destinatie<<" are costul "<<dist[destinatie]<<" si trece prin nodurile: ";
    while(top>=0){
        cout<<stiva[top--]<<" ";
    }
    cout<<endl;
    delete[] stiva;

}