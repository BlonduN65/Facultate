def citire_multime():
    multime=set()
    n=int(input("Dati numarul de elemente al multimii: "))

    for i in range(n):
        elem=(input("Val: "))
        multime.add(elem)

    return multime


def tabelul_apartenenta(A, B,  nume_operatie):
   
    if nume_operatie == "A U B":
        rezultat = A.union(B)
    elif nume_operatie == "A n B":
        rezultat = A.intersection(B)
    elif nume_operatie == "A\\B":
        rezultat = A.difference(B)
    elif nume_operatie == "B\\A":
        rezultat = B.difference(A)
    elif nume_operatie == "A Delta B":
        rezultat = A.symmetric_difference(B)
    else:
        rezultat = set()

   
    univers = sorted(A.union(B))

    
    print(f"\nTabela de apartenenta pentru {nume_operatie}:")
    print("Element | A | B | Rezultat")
    print("-" * 30)

    for x in univers:
        ap_A = 1 if x in A else 0
        ap_B = 1 if x in B else 0
        ap_Rez = 1 if x in rezultat else 0 
        print(f"   {x}    | {ap_A} | {ap_B} |    {ap_Rez}")