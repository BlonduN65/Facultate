def  expresie_1():
    print("%10s %10s %12s %10s %10s" %("p","q","expr1","expr2","expr"))
    for p in (True, False):
        for q in (True, False):
            expr1=p and (not q)
            expr2=not(p)or q
            expr=not(expr1 and expr2)
            print("%10s %10s %12s %10s %10s" %(p,q,expr1,expr2,expr))

def implicatie(p,q):
    if p:
        return q
    else:
        return True
def echivalenta(p,q):
    if p==q:
        return True
    else:        
        return False

def expresie_2():
    print("%10s %10s %10s %12s %10s %10s" %("p","q","r","expr1","expr2","expr"))
    for p in (True, False):
        for q in (True, False):
            for r in (True, False):
                expr1=echivalenta(q,implicatie(r,not p))
                expr2=echivalenta(implicatie(not q,p),r)
                expr=expr1 or expr2
                print("%10s %10s %10s %12s %10s %10s" %(p,q,r,expr1,expr2,expr))

def expresie_3():
    print("%10s %10s %10s %12s %10s %10s" %("p","q","r","expr1","expr2","expr"))
    for p in (True, False):
        for q in (True, False):
            for r in (True, False):
                expr1=(p or q)and (not p or r)
                expr2=q or r
                expr= implicatie(expr1,expr2)
                print("%10s %10s %10s %12s %10s %10s" %(p,q,r,expr1,expr2,expr))