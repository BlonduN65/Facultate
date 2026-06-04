def citire_multime():
    multime=set()
    n=int(input("Dati numarul de elemente din multime: "))
    for i in range(n):
        element=int(input("Dati elementul: "))
        multime.add(element)
    return multime

def reuniune(A,B):
    print("Reuniunea multimilor A si B este: ",A.union(B))

def intersectie(A,B):
    print("Intersectia multimilor A si B este: ",A.intersection(B))

def diferenta_simertica(A,B):
    print("Diferenta simetrica a multimilor A si B este: ",A.symmetric_difference(B))

def disjuncte(A,B):
    if A.isdisjoint(B):
        print("Multimile A si B sunt disjuncte.")
    else:
        print("Multimile A si B nu sunt disjuncte.")

def stergere(A):
    for x in A.copy():
        if x %2 == 0:
            A.remove(x)

    print("Multimea A dupa stergerea elementelor pare este: ",A)

def produs_cartesian(A,B):
    rezultat=[]
    for a in A:
         for b in B:
             rezultat.append((int(a),int(b)))
    print("Produsul cartesian al multimilor A si B este: ",rezultat)