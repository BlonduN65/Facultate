def implicatie(p,q):
    if p:
        return q
    else:
        return True
def subpunct_a():
    este_tautologie=True
    este_contradictie=True
    for p in (True,False):
        for q in (True,False):
            for r in (True,False):
                expr1=(p or q )and (not p or r)
                exp=implicatie(expr1,(q or r))
                if exp==False:
                    este_tautologie=False
                if exp==True:
                    este_contradictie=False
    if este_tautologie:
        print("Tautologie")
    elif este_contradictie:
        print("Contradictie")
    else:
        print("Nu este nici tautologie, nici contradictie")

def subpunct_b():
    este_tautologie=True
    este_contradictie=True
    for p in (True,False):
        for q in (True,False):
            for r in (True,False):
                expr1=(implicatie(p,q) and implicatie(q,r))
                expr=implicatie(expr1,implicatie(p,r))
                if expr==False:
                    este_tautologie=False
                if expr==True:
                    este_contradictie=False
    if este_tautologie:
        print("Tautologie")
    elif este_contradictie:
        print("Contradictie")
    else:
        print("Nu este nici tautologie, nici contradictie")

def biconditional(p,q):
    if p==q:
        return True 
    else:
        return False
def subpunct_c():
    este_tautologie=True
    este_contradictie=True
    for p in (True,False):
        for q in (True,False):
                expr1=biconditional(q,implicatie(q,p))
                expr=implicatie(expr1,p)
               
                if expr==False:
                    este_tautologie=False
                if expr==True:
                    este_contradictie=False
    if este_tautologie:
        print("Tautologie")
    elif este_contradictie:
        print("Contradictie")
    else:
        print("Nu este nici tautologie, nici contradictie")
