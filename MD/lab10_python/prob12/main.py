import functii as f


def main():

    A=f.citire()
    M=f.generare_matrice(A)
    print(f.desenareGraf(f.generare_graf(M)))

    R=f.inchidere_reflexiva(M)
    print(f.desenareGraf(f.generare_graf(R)))

    T=f.inchidere_tranzitiva(M)
    print(f.desenareGraf(f.generare_graf(T)))

    S=f.inchidere_simetrica(M)
    print(f.desenareGraf(f.generare_graf(S)))

if __name__=="__main__":
    main()
