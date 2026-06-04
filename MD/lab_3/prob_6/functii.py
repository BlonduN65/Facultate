def subpunctul_i():
    este_tautologie = True 

    for p in (True, False):
        for q in (True, False):
            expr1 = not p or q
            expr2 = p and (not q)
            expr = expr1 or expr2
            
            if expr != True:
                print("NU este tautologie pentru p =", p, "si q =", q)
                este_tautologie = False
                break 
        if not este_tautologie:
            break

    if este_tautologie:
        print("Expresia este o TAUTOLOGIE.")

def subpunctul_ii():
    este_tautologie = True
    for p in(True,False):
        for q in (True , False):
            expr1=p and (not q)
            expr2=(not p) or q
            expr=not(expr1 and expr2)
            if expr != True:
                print("NU este tautologie pentru p =", p, "si q =", q)
                este_tautologie = False
                break
    if este_tautologie:
        print("Expresia este o TAUTOLOGIE.")

def biconditie(p,q):
    if p==q:
        return True 
    else:
        return False
    
def subpunctul_iii():
    este_tautologie = True
    for p in (True , False):
        for q in (True,False):
            for r in (True ,False):
                expr1=p and( q or r)
                expr2=(p and q) or (p and r)
                expr=biconditie(expr1,expr2)
                if expr != True:
                    print("NU este tautologie pentru p =", p, "q =", q, "si r =", r)
                    este_tautologie = False
                    break
    if este_tautologie:
        print("Expresia este o TAUTOLOGIE.")
def implicatie(p,q):
    if p:
        return q
    else:
        return True
def subpunctul_iv():
    este_tautologie=True 
    for p in (True,False):
        for q in (True,False):
            for r in (True,False):
                expr1=(p or q) and(not p or r)
                expr2=q or r
                expr=implicatie(expr1,expr2)
                if expr != True:
                    print("NU este tautologie pentru p =", p, "q =", q, "si r =", r)
                    este_tautologie = False
                    break
    if este_tautologie:
        print("Expresia este o TAUTOLOGIE.")

def subpunctul_v():
    este_tautologie=True 
    for p in (True,False):
        for q in (True , False):
            expr1= p and(implicatie(p,q))
            expr=implicatie(expr1,q)
            if expr != True:
                print("NU este tautologie pentru p =", p, "si q =", q)
                este_tautologie = False
                break
    if este_tautologie:
        print("Expresia este o TAUTOLOGIE.")













