import functii as f

def main():
    A={}
    B={}
    A=set(input("Introdu elementele multimii A: "))
    B=set(input("Introdu elementele multimii B: "))
    print(A)
    print(B)
    
    f.tabelul_apartenenta(A,B,"A U B")
    f.tabelul_apartenenta(A,B,"A n B")
    f.tabelul_apartenenta(A,B,"A\\B")
    f.tabelul_apartenenta(A,B,"B\\A")
    f.tabelul_apartenenta(A,B,"A Delta B")
    


if __name__=="__main__":
    main()