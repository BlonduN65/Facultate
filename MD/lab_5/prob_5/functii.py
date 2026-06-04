def M(x,y):
    return x==y

def T(x,y):
    return x==y

def citire_matrice(n,nume_matrice):
    matrice=[]
    for i in range(n):
        linie=[]
        for j in range(n):
            val=int(input(f"{nume_matrice}[{i}][{j}]="))
            linie.append(val)
        matrice.append(linie)

    return matrice


def prop_a(M,T):
    return  M[0][1]==0 and T[0][1]

def prop_b(T,n):
    for i in range(n):
        if T[i][i]==1:
            print("True")
        else:
            print("False")


def prop_c(M,T,n):
    k=0
    for i in range(n):
        contor=0
        for j in range(n):
            if i!=j and (M[i][j]==1 or T[i][j]):
                contor+=1
        if contor ==n-1:
            print("True")
            k=1     

    if k==0:
        print("False")


def prop_d(M,T,n):
    ok=0
    for i in range(n):
        for j in range(n):
            if i!=j:
                if M[i][j]==1 and T[j][i]==1:
                    print ("True")
                    ok=1
    if ok==0:
        print("False")


def prop_e(M,T,n):
    contor=0
    for i in range(n):
        for j in range(n):
            if M[i][j] ==1 or T[i][j] ==1:
                contor+=1


    if contor>1:
        print("True")
    else:
        print("False")

def prop_f1(M,n):
    k=0
    for i in range(n):
        nr=0
        for j in range(n):
            if M[i][j]==1:
                nr+=1
        if nr==2:
            k=1

    if k!=0:
        print("True")
    else:
        print("False")

def prop_g(T,n):
    k=0
    for i in range(n):
        ok=0
        for j in range(n):
            if T[i][j]==1:
                ok+=1
        if ok==1:
            k=1

    if k:
        print("True")
    else:
        print("False")
