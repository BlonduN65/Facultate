#include <iostream>
#include "header.h"
using namespace std;
int main(){
/*    int n ,m,k,l,cost;
    cin>>n>>m;
    int **a=(int **)malloc(n*sizeof(int*));
    for (int i=0;i<n;i++){
        a[i]=(int *)malloc(m*sizeof(int));
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            a[i][j]=0;
        }

    for (int i=0;i<m;i++)
            
    {       
          
            cin>>k;
            cin>>l;
            cin>>cost;
           
            a[k-1][l-1]=cost;
        }
        cout<<"Afisare matrice noduri si cost"<<endl;
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }*/
                 Nod* V[MAX];     
                 int M[MAX] = {0}; 
                 int L[MAX];       
                 int n, m, startNode, contor = 0;

                 citireGraf(V, n, m);
                 cin >> startNode;

                DFS_recursiv(V, M, L, contor, startNode, n);
    
                afisareRezultat(L, contor);

    
   
    return 0;
}
