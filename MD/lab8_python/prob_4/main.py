import functii as f
from functools import reduce
from numpy import abs
from numpy import sqrt
def main():

    v=f.citire_vector()
    pozitive=list(filter(lambda x:x>0,v))
    negative=list(filter(lambda x:x<0,v))
    zero=list(filter(lambda x :x==0,v))
    print(list(pozitive))
    print(len(pozitive))
    print("*"*30)
    print(list(negative))
    print(len(negative))
    print(len(zero))
    
    patrat=map(lambda x:x**2,filter(lambda x:x>0,v))
    print("Maximult fiecarui patrat pozitiv este: ",list(patrat))

    valori_abs=map(abs,negative)
    suma=reduce(lambda x ,y:x+y,valori_abs,0)
    print("Suma valorilor negative este:",suma)
    
    patrate=list(map(lambda x :x**2,v))
    suma_p=reduce(lambda x,y:x+y,patrate,0)
    norma=sqrt(suma_p)
    print("Norma:",norma)
if __name__=="__main__":
    main()
