import functii as f

def main():

    x=int(input("Dati un numar: "))

    print(f.suma_cifre(x))
    print("produsul cifrelor este: ",f.produs_cifre(x))

if __name__ == "__main__":      
    main()