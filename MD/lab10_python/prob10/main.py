import functii as f


def main():

    A={1,2,3,4}
    E=f.citire()
    print(E)
    M=f.generare_matrice(E)
    f.desenareGraf(f.generare_graf(M))
        

    relatii={
        "Reflexivitate":f.reflexiva(M),
        "Simetrica":f.simetrie(M),
        "Tranzitivitate":f.tranzitivitate(M),
        "Asimetrica":f.asimetrica(M),
        "Antisimetrica":f.antisimetrica(M)}

    print("Relatiile sunt:")
    for relatie,functie in relatii.items():
        print(f"{relatie}:{functie}")


if __name__=="__main__":
    main()
