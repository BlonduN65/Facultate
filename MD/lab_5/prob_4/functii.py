def pozitive(x):
    return x>0
def negative(x):
    return x<0


def subpunctul_a(U):
    rez=False
    lista=[]
    for i in U:
        for j in U:
            if negative(i) and  negative(j):
                if i*j>0:
                    lista.append((int(i),int(j)))
                    rez=True

    print("a)")
    print (rez)
    if rez:
        print(lista)
   

def subpunctul_b(U):
    rez=False
    lista=[]
    for i in U:
        for j in U:
            if pozitive(i) and pozitive(j):
                if (i+j)/2 >=0:
                    rez=True
                    lista.append((int(i),int(j)))

    print("b)")
    print (rez)
    if rez:
        print(lista)
        

def subpunctul_c(U):
    rez=False
    lista=[]
    for i in U:
        for j in U:
            if negative(i) and negative(j):
                if i-j>0:
                    rez=True
                    lista.append((int(i),int(j)))

    print("c)")
    print(rez)
    if rez:
        print(lista)



def subpunctul_d(U):
    rez=False
    lista=[]
    for i in U:
        for j in U:
            if pozitive(i) and pozitive(j):
                if abs(i+j)<(abs(i)+abs(j)):
                    rez=True
                    lista.append((int(i),int(j)))


    print("d)")
    print(rez)
    if rez:
        print(lista)
