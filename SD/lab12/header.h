#ifndef HEADER_H_
#define HEADER_H_
const int MAX = 100;

struct Nod {
    int v;         
    int cost;      
    Nod* urm;      
};

void citireGraf(Nod* V[MAX], int &n, int &m);
void DFS_recursiv(Nod* V[MAX], int M[MAX], int L[MAX], int &contor, int i, int n);
void afisareRezultat(int L[MAX], int contor);

#endif