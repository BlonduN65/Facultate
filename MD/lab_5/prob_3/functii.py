def Q(x):
    return 't' in x
def R(x):
    return 'd' in x
def S(x):
    return 'p' in x
def P(x,U,nrLaturi):
    idx=U.index(x)
    return nrLaturi[idx]>=2

def subpunctul_a(U,nrLaturi):
    rez=False
    lista=[]
    for x in U:
        if Q(x) and P(x,U,nrLaturi):
            rez=True
            lista.append(x)


    print("a)")
    print (rez)
    if rez:
        print(lista)


def subpunctul_b(U,nrLaturi):
    rez=True
    lista=[]
    for x in U:
        if P(x,U,nrLaturi):
          if R(x):
              lista.append(x)
          else:
              rez=False

    print("b)")
    print(rez)
    if rez:
        print(lista)


def subpunctul_c(U,nrLaturi):
    rez=False
    lista=[]
    for x in U:
        if P(x,U,nrLaturi) and S(x):
            rez=True
            lista.append(x)

    print("c)")
    print(rez)
    if rez:
        print(lista)

def subpunctul_d(U,nrLaturi):
    rez=True
    lista=[]
    for x in U:
        if S(x) :
            if P(x,U,nrLaturi):
                lista.append(x)
            else:
                rez=False

    print("d)")
    print(rez)
    if rez:
        print(lista)



