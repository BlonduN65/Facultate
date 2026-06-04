def tabela_apartenenta(A,B,C,U,nume_operatie):
    
    rezultat=set()
    if nume_operatie =="A U B":
        rezultat=A.union(B)
    elif nume_operatie =="A n C":
        rezultat=A.intersection(C)
    elif nume_operatie=="A n B U C":
        rezultat=C.union(A.intersection(B))
    elif nume_operatie=="AU \C":
        rezultat=(A.difference(U)).difference(C)
    elif nume_operatie=="A Delta C \ B":
        rezultat=(A.symmetric_difference(C)).difference(B)

    print(f"\nTabelul de apartenenta pentru {nume_operatie}: ")
    print("Element A | B | C | Rezultat ")
    print("*"*30)

    for x in U:
        ap_A=1 if x in A else 0
        ap_B=1 if x in B else 0
        ap_C=1 if x in C else 0
        ap_rezultat=1 if x in rezultat else 0
        print(f" {x} | {ap_A} | {ap_B} | {ap_C} | {ap_rezultat} ")