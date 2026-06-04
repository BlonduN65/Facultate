def citire_multime():
    multime=set()
    n=int(input("Nr de elemente al multimii:"))
    for i in range(n):
        el=int(input(f"el[{i}]"))
        multime.add(el)

    return multime

def produs_cartezian(A,B):
    rezultat=[]
    for x in A:
        for y in B:
            rezultat.append((x,y))

    return rezultat