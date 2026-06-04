def tabela_apartenenta(R,S,U,nume_operatie):
    rezultat=set()

    if nume_operatie=="R U S":
        rezultat=R.union(S)
    elif nume_operatie=="R\\U and S\\U":
        rezultat=U.difference(S.union(R))
    elif nume_operatie =="R\\S":
        rezultat=R.difference(S)

    print(f"Tabela de apartenenta pentru {nume_operatie}: ")
    print("Element R | S | Rezultat ")
    print("*"*30)
    for x in  U:
        ap_R=1 if x in R else 0
        ap_S=1 if x in S else 0
        ap_rez=1 if x in rezultat else 0
        print(f"{x} | {ap_R}| {ap_S} | {ap_rez} ")