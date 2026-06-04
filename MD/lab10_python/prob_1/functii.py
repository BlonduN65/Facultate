def genereaza_relatie(A,B,conditie):
    R=[]
    for a in A:
        for b in B:
            if conditie(a,b):
                R.append((a,b))

    return R

def cmmdc(a,b):
    if (a>b):
        aux=a
        a=b
        b=aux

    while(b):
        r=b/a
        b=a
        a=r

    return(b)
