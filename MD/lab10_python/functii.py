import numpy as np
def citire_matrice():
    n=int(input("Dimensiunea matricei este: "))

    M=np.zeros((n,n),dtype=int)

    for i in range(n):
        for j in range(n):
            M[i][j]=int(input(f"M[{i}][{j}]"))

    return M

def afiseaza_perechi(A,n):
    p=[]
    for i in range(n):
        for j in range(n):
            if A[i][j]==1:
                p.append((i,j))

    return p

def intersectie(A,B):
    return np.logical_and(A,B).astype(int)

def reuniune(A,B):
    return np.logical_or(A,B).astype(int)

def produs_boolean(A,B):
    C=np.dot(A,B)
    return (C>0).astype(int)

