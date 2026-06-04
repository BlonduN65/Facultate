#include "header.h"
using namespace std;
#include <iostream>


void citireGraf(Nod* V[MAX], int &n, int &m) {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        V[i] = nullptr;
    }

    for (int k = 0; k < m; k++) {
        int i, j, c;
        cin >> i >> j >> c;
        
        
        Nod* nou = new Nod;
        nou->v = j;
        nou->cost = c;
        nou->urm = V[i];
        V[i] = nou;
    }
}


void DFS_recursiv(Nod* V[MAX], int M[MAX], int L[MAX], int &contor, int i, int n) {
            L[contor++] = i;
            M[i] = 1;

        
            Nod* p = V[i];
            while (p != nullptr) {
                if (M[p->v] == 0) {
                    DFS_recursiv(V, M, L, contor, p->v, n);
                }
                p = p->urm;
    }
}

void afisareRezultat(int L[MAX], int contor) {
    for (int i = 0; i < contor; i++) {
            cout << L[i] << " ";
    }
    cout << endl;
}