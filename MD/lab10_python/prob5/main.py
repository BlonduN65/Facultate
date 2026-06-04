import functii as f
import numpy as np
def main():
    A=f.citire()
    f.afisare(A)
    a=np.transpose(A)
    b=np.logical_not(A).astype(int)
    c=np.dot(A,A)
    f.afisare(a)
    f.afisare(b)
    f.afisare(c)
    
    f.desenare_graf(a,titlu="R la puterea -1")
    f.desenare_graf(b,titlu="R barat")
    f.desenare_graf(c,titlu="R la puterea a 2 a")

if __name__=="__main__":
    main()
