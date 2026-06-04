def implicatie(p,q):
    if p:
        return q
    else:
        return True
    

def   subpunctul_ii():
    print("%10s %10s %12s %10s" %("p","q","expr1","expr2"))
    for p in [True,False]:
        for q in [True,False]:
            expr1=implicatie(p, q)
            expr2=implicatie(not p or q,p)
            if expr1 and expr2 == True :
                    pTemp=p
                    qTemp=q
                    print("** %7s %10s %12s %10s" %(p,q,expr1,expr2))
            else:
                print("%10s %10s %12s %10s" %(p,q,expr1,expr2))

    print ("\n\n\n")
    print("val(p)= %d",pTemp)
    print("val(q)= %d",qTemp)
            




def  subpunctul_i():
    print("%10s %10s %12s %10s" %("p","q","expr1","expr2"))
    for p in [True,False]:
        for q in [True,False]:
            expr1=implicatie(p,p and q)
            expr2=(p or q )and not(p and q)
            if expr1 and expr2 == True :
                    pTemp=p
                    qTemp=q
                    print("** %7s %10s %12s %10s" %(p,q,expr1,expr2))
            else:
                print("%10s %10s %12s %10s" %(p,q,expr1,expr2))

    print ("\n\n\n")
    print("val(p)= %d",pTemp)
    print("val(q)= %d",qTemp)
