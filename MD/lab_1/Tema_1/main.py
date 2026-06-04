import functii as F

def main():

    x1=int(input("Introduceti valoarea numarului pe care doriti sa calculati factorialul: "))
    print("Factorialul numarului")
    print (F.factorial(x1))

    k=int(input("Introduceti puterea la care numarul va fi ridicat: "))
    print("Ridicarea la putere a numarului")
    print (F.ridicare_la_putere(x1, k))
    
    print("Fibonacci")
    print (F.fibonacci(x1))

    print("Aranjamente:")
    print(F.aranjamente(x1, k))


if __name__ == "__main__":
    main()