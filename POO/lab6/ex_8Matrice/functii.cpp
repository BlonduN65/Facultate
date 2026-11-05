#include "header.h"
#include <cassert>

Matrice::Matrice(int m, int n) {
    assert(m >= 1 && n >= 1);
    
    this->m = m;
    this->n = n;

    this->elemente = new int[m * n]{};
}

Matrice::~Matrice() {
    delete[] elemente;
}

int Matrice::getcoloane() const {
    return n; // returneaza n (coloanele)
}

int Matrice::getLinii() const {
    return m; // returneaza m (liniile)
}

int& Matrice::operator()(int i, int j) {
    assert(i >= 0 && i < m);
    assert(j >= 0 && j < n);

    return elemente[i * n + j];
}

int Matrice::operator()(int i, int j) const {
    assert(i >= 0 && i < m);
    assert(j >= 0 && j < n);

    return elemente[i * n + j];
}