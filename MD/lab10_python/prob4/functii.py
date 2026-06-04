import numpy as np

def citire():
    n=int(input("Dati numarul de linii:"))
    m=int(input("Dati numarul de coloate"))
    M=np.zeros((n,m),dtype=int)

    for i in range(n):
        for j in range(m):
            M[i][j]=int(input(f"M[{i}][{j}]="))

    return M

def produs(A,B):
    C=np.dot(A,B)
    return (C>0).astype(int)
