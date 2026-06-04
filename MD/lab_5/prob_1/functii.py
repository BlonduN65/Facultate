def citireUnivers():
    U=[]
    n=int(input("n="))
    for i in range(0,n):
        print ("U[",i,"]=",end='')
        U.append(int(input()))

    return U
    
def Q(x,y):
    r=((x+y) == (x-y))
    return r



def subpunctul_a(U):
    
    
        listaValori=[]
        rez=False

        for y in U:
            if Q(5,y):
                rez=True
                listaValori.append(int(y))
        print("a)")
        print("Valoarea expresiei este:")
        print(rez)
        if rez:
            print("Valorile pentru care expresia este adevarata sunt:\n")
            print(listaValori)

        print("\n")

    
def subpunctul_b(U):
    rez=False
    listaValori=[]
    for x in U:
        if Q(x,4):
            rez=True
            listaValori.append(x)
    print("b)")
    print(rez)
    if rez:
        print("Valorile pentru care expresia este adevarata sunt:\n")
        print(listaValori)

    print("\n")

    
def subpunctul_c(U):
    
    rez=False
    listaPerechi=[]

    for x in U:
        rez_y=False
        for y in U:
            if Q(x,y):
                rez_y=True
                listaPerechi.append((x,y))

        if rez_y:
            rez=True


    print("c)")
    print(rez)
    print("Valorile pentru care expresia este adevarata sunt:\n")
    print(listaPerechi)

def subpunctul_d(U):
    rez=True
    listaPerechi=[]
    for y in U:
        rez_x=False
        for x in U:
            if Q(x,y):
                rez_x=True
                listaPerechi.append((x,y))

        if rez_x:
            rez=False


    print("d")
    print(rez)
    if rez:
        print("Valorile pentru care expresia este adevarata sunt:\n")
        print(listaPerechi)

def subpunctul_e(U):
    rez=False
    listaPerechi=[]
    for y in U:
        rez_x=True
        for x in U:
            if not Q(x,y):
                rez_x=False
                break
            else:
                rez_x=True
                listaPerechi.append((x,y))
        if rez_x:
            rez=True
    print("e)")
    print(rez)
    if rez:
        print("Valorile pentru care expresia este adevarata sunt:\n")
        print(listaPerechi)

