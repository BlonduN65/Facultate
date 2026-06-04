def genereaza3_tuple(A):
    rezultat=[]
    for e1 in A:
        for e2 in A:
            for e3 in A:
                rezultat.append((e1,e2,e3))
                
    return rezultat

def genereaza4_tuple(A):
    rezultat=[]
    for e1 in A:
        for e2 in A:
            for e3 in A:
                for e4 in A:
                    rezultat.append((e1,e2,e3,e4))

    return rezultat