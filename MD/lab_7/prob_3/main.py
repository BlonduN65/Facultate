import functii as f

def main():

    R={"MD","F","PL","ENG"}
    S={"MD","MS","PC","PL"}
    U={"MD","MS","PL","SD","PC","ETH","ENG","F"}

    print(S.union(R))
    f.tabela_apartenenta(R,S,U,"R U S")
    
    print(U.difference(R.union(S)))
    f.tabela_apartenenta(R,S,U,"R\\U and S\\U")

    print (R.difference(S))
    f.tabela_apartenenta(R,S,U,"R\\S")

if __name__=="__main__":
    main()