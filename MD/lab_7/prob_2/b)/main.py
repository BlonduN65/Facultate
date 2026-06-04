import functii as f

def main():
    
    U=set(range(1,11))
    A=set(map(int,input("Elementele multimii A sunt: ").split()))
    B=set(map(int,input("Elementele multimii B sunt: ").split()))
    C=set(map(int,input("Elementele multimii C sunt: ").split()))

    f.tabela_apartenenta(A,B,C,U,"A U B")
    f.tabela_apartenenta(A,B,C,U,"A n C")
    f.tabela_apartenenta(A,B,C,U,"A n B U C")
    f.tabela_apartenenta(A,B,C,U,"AU \C")
    f.tabela_apartenenta(A,B,C,U,"A Delta C \ B")


if __name__=="__main__":
    main()