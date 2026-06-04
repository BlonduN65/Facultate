import functii as f


def main():

    A=f.citire()
    B=f.citire()

    print("a)")
    f.afisare(f.reuniune(A,B))
    
    print("b)")
    f.afisare(f.intersectie(A,B))

    print("c)")
    f.afisare(f.compunere(A,B))

    print("d)")
    f.afisare(f.diferenta(A,B))


if __name__=="__main__":
    main()
