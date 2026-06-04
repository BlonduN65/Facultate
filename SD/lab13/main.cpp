#include <iostream>
#include "header.h"
using namespace std;
int main(){

    int n=5;
    int **graf=new int*[n];
    for(int i=0;i<n;i++){
        graf[i]=new int[n];
        for(int j=0;j<n;j++){
            graf[i][j]=0;
        }
    }
    graf[0][1]=10;
    graf[0][2]=3;
    graf[2][1]=1;
    graf[1][3]=2;
    graf[2][3]=8;
    graf[3][4]=7;

    unsigned int *dist=new unsigned int[n];
    int *previous=new int[n];

    algoritmDijkstra(graf,n,0,dist,previous);
    afisareDrumMinim(0,3,dist,previous);

    for(int i=0;i<n;i++){
        delete[] graf[i];
    }
    delete[] graf;
    delete[] dist;
    delete[] previous;


    return 0;

}