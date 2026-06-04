import functii as f
def main():
    
    print("%10s %10s %11s" % ("p","q","p->q"))
    for p in (False,True):
        for q in (False,True):
            print("%10s %10s %11s" % (p,q,f.implicatie(p,q)))    

            
    print("-------------------------------")
    print("%10s %10s %11s" % ("p","q","p<->q"))
    for p in (False,True):
        for q in (False,True):
            print("%10s %10s %11s" % (p,q,f.echivalenta(p,q)))

            
    print("-------------------------------")
    print("%10s %10s %11s" % ("p","q","p v q"))
    for p in (False,True):
        for q in (False,True):
            print("%10s %10s %11s" % (p,q,f.disjunctie(p,q)))

    print("-------------------------------")
    print("%10s %10s %11s" % ("p","q","p ^ q"))
    for p in (False,True):
        for q in (False,True):
            print("%10s %10s %11s" % (p,q,f.conjunctie(p,q)))
if __name__ == "__main__":
    main()