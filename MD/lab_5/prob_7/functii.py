def implicatie(x,y):
    if x:
        return y
    else:
        return True

def prob_a():
    este_tautologie=True
    for a in (True,False):
        for b in (True,False):
            for c in(True , False):
                p1=implicatie(a,b and c)
                p2=not b
                concluzia=not a
                exp=not(p1 and p2) or concluzia
                
                if exp==False:
                    este_tautologie=False


    print("Este tautologie:")
    print(este_tautologie)


def prob_b():
    este_tautologie=True
    for s in(True,False):
        for p in (True,False):
            for q in (True , False):
                for r in (True , False):
                    p1=implicatie(s,r)
                    p2=implicatie(p or q, not r)
                    p3=implicatie(not s, implicatie(not q ,r))
                    p4=p
                    concluzia=q
                    exp=not(p1 and p2 and p3 and p4)or concluzia

                    if exp==False:
                        este_tautologie=False

    print("Este tautologie:")
    print(este_tautologie)



