def subpunctul_a(A,B,C,D):
    nr_A=0
    nr_B=0
    nr_C=0
    nr_D=0

    for x in A:
        if x>=5:
            nr_A+=1
    for x in B:
        if x >=5:
            nr_B+=1

    for x in C:
        if x>=5:
            nr_C+=1

    for x in D:
        if x>=5:
            nr_D+=1

    print("Notele din A: ",nr_A)
    print("Notele din B: ",nr_B)
    print("Notele din C: ",nr_C)
    print("Notele din D: ",nr_D)


def subpunctul_b(A,B,C,D):
    nr_A=0
    nr_B=0
    nr_C=0
    nr_D=0

    for x in A:
        if x>=9:
            nr_A+=1
    for x in B:
        if x >=9:
            nr_B+=1

    for x in C:
        if x>=9:
            nr_C+=1

    for x in D:
        if x>=9:
            nr_D+=1

    print("Notele din A: ",nr_A)
    print("Notele din B: ",nr_B)
    print("Notele din C: ",nr_C)
    print("Notele din D: ",nr_D)

def subpunctul_c(A,B,C,D):
    nr_A=0
    nr_B=0
    nr_C=0
    nr_D=0

    for x in A:
        if x>=5 and x<9:
            nr_A+=1
    for x in B:
        if x>=5 and x<9:
            nr_B+=1

    for x in C:
       if x>=5 and x<9:
            nr_C+=1

    for x in D:
        if x>=5 and x<9:
            nr_D+=1

    print("Notele din A: ",nr_A)
    print("Notele din B: ",nr_B)
    print("Notele din C: ",nr_C)
    print("Notele din D: ",nr_D)



def subpunctul_d(A,B,C,D):
    
    for x in list(A):
        if x%3==0:
            A.discard(x)
    for x in list(B):
        if x%3==0:
            B.discard(x)

    for x in list(C):
      if x%3==0:
            C.discard(x)

    for x in list(D):
        if x%3==0:
            D.discard(x)

    print("Notele din A: ",A)
    print("Notele din B: ",B)
    print("Notele din C: ",C)
    print("Notele din D: ",D)







