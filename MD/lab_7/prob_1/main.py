import functii as f


def main():
    A={}
    B={}
    A=f.citire_multime()
    B=f.citire_multime()
    f.reuniune(A,B)
    f.intersectie(A,B)
    f.diferenta_simertica(A,B)
    f.disjuncte(A,B)
    f.stergere(A)
    f.produs_cartesian(A,B)





if __name__ == "__main__":
    main()
