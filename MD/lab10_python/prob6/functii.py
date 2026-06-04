import numpy as np


def citire():
    n=int(input("Dati rangul matricei: "))
    M=np.zeros((n,n),dtype=int)

    for i in range(n):
        for j in range(n):
            M[i][j]=int(input(f"M[{i+1}][{j+1}]"))

    return M


def afisare(M):
    
    l=[]
    for i in range(3):
        for j in range(3):
            if M[i][j]==1:
                l.append((i+1,j+1))

    print(l)



def reuniune(A,B):
    return np.logical_or(A,B)

def intersectie(A,B):
    return np.logical_and(A,B)


def compunere(A,B):
    return (np.dot(A,B)>0).astype(int)

def diferenta(A,B):
    return np.logical_and(A,np.logical_not(B)).astype(int)

