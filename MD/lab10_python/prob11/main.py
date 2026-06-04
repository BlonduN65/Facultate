import functii as f


def main():

    A=f.citire()
    M=f.generare_matrice(A)
    print(f.desenareGraf(f.generare_graf(M)))
    
    R=f.inchidere_reflexiva(M)
    print(f.desenareGraf(f.generare_graf(R)))
    As=f.inchidere_simetrica(M)
    print(f.desenareGraf(f.generare_graf(As)))
    T=f.inchidere_tranzitiva(M)
    print(f.desenareGraf(f.generare_graf(T)))
if __name__=="__main__":
    main()
