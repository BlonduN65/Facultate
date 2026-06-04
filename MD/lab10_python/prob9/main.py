import functi as f



def main():
    A=f.citire()
    f.afisare(A)
    f.desenareGraf(f.generare_graf(A))
    relatii={
        "Simetrie":f.simetrie(A),
        "Reflexivitate":f.reflexiva(A),
        "Tranzitivitate":f.tranzitiva(A),
        "Asimetrica":f.asimetrica(A),
        "Antisimetria":f.antisimetrica(A)}
    print("Analiza Relatiei: ")
    for prop , valoare in relatii.items():
        print(f"-{prop}:{valoare}")

if __name__=="__main__":
    main()
