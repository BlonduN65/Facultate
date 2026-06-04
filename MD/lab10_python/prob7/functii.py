import numpy as np
def citire_matrice():
    n=int(input("Dimensiunea matricei : "))
    M=np.zeros((n,n),dtype=int)

    for i in range(n):
        for j in range(n):
            M[i][j]=int(input(f"M[{i}][{j}]"))

    return M



def afisare(M):
    n=len(M)
    l=[]
    for i in range(n):
        for j in range(n):
                if M[i][j]==1:
                        l.append((i+1,j+1))
    print(l)


def intersectie(A,B):
    return np.logical_and(A,B).astype(int)

def reuniune(A,B):
    return np.logical_or(A,B).astype(int)

def diferenta(A,B):
    return np.logical_and(A,np.logical_not(B)).astype(int)

def compunere(A,B):
    return (np.dot(A,B)>0).astype(int)



