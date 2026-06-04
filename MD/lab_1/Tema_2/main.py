import functii as f

def main():
    n=int(input("n="))
    v1=[]
    # //v2=[]
    v1=f.citire_vector(n)
    # v2=f.citire_vector(n)

    # punct=int(input("p="))
    # print("Valoarea polinomului este:")
    # print(f.valoare_polinom(v1,n-1,punct))
    
    # print("Produsul scalar este:")
    # p= f.produs_scalar(v1,v2,n-1)
    # print(p)    

   # f.prob_3(v1,n-1)
    x=f.cmmdc_vector(v1,n-1)
    print("Cel mai mare divizor comun este:")
    print(x)
if __name__ == "__main__":      
     main()