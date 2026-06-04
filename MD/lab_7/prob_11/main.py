import functii as f


def main():

    A=set()
    B=set()
    A=f.citire_multime()
    B=f.citire_multime()

    print("A x B",f.produs_cartezian(A,B))
    print("*"*30)
    print("B x A",f.produs_cartezian(B,A))






if __name__=="__main__":
    main()

