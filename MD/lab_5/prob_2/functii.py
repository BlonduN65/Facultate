def subpunctul_a(U1,U2):
    listaValori=[]
    rez=False
    for x in U1:
        for y in U2:
            if x*x==y:
                rez=True
                listaValori.append((int(x),int(y)))


    print("a)")
    print(rez)
    if rez:
        print("Lista valorilor pentru subpunctul a este: ")
        print(listaValori)

def subpunctul_b(U1,U2):
    rez=True
    listaValori=[]
    for y in U2:
        rez_x=False
        for x in U1:
         if x*x==y:
             rez_x=True
             listaValori.append((int(x),int(y))) 
             break
        if not rez_x:
            rez=False
                                                      
                                                      
    print("b)")                                     
    print(rez)                                      
    if rez:                                         
          print("Lista valorilor pentru subpunctul b este: ")
          print(listaValori) 

def subpunctul_c(U3):
    rez=True
    listaValori=[]
    for x in U3:
        rez_x=False
        for y in U3:
            if x*y==1:
                rez_x=True
                listaValori.append((int(x),int(y)))

        if not rez_x:
            rez=False

    print("c)")                                       
    print(rez)                                      
    if rez:                                         
        print("Lista valorilor pentru subpunctul c este: ")
        print(listaValori) 

def subpunctul_d(U3):
    rez=True
    listaValori=[]
    for x in U3:
        rez_x=False
        for y in U3:
            if x*y-1<0.001:
                rez_x=True
                listaValori.append((int(x),int(y)))
                break
        if not rez_x:
            rez=False


    print("d)")
    print(rez)
    if rez:
        print("Lista valorilor pentru subpunctul c este: ")
        print(listaValori)


