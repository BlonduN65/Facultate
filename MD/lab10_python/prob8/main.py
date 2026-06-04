import functii as f


def main():
    A=f.citire()
   # f.desenareGraf(f.generare_graf(A))
    
    proprietati={
            "Reflexiva":f.reflexivitate(A),
            "Simetrica":f.simetrica(A),
            "Antisimetrica":f.antisimetrica(A),
            "Tranzitiviate":f.tranzitivitate(A)
            }

    print("Analiza Relatiei:")
    for prop,valoare in proprietati.items():
        print(f"-{prop}:{valoare}")





if __name__=="__main__":
    main()
