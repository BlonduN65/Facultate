def citire():
    inventory=[]
    n=int(input("Dati numarul de produse: "))
    for i in range(n):
        nume=input("Introduceti numele produsului")
        pret=float(input("Introduceti pretul produsului: "))
        stoc=int(input("Introduceti stocul produsului: "))

        produs={"nume":nume,"pret":pret,"stoc":stoc}
        inventory.append(produs)

    return inventory
