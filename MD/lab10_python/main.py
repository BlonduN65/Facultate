import functii as f
import numpy as np


def main():
    
    A=f.citire_matrice()
    n=3
    B=f.citire_matrice()
    ra=f.afiseaza_perechi(A,n)
    print(ra)
    rb=f.afiseaza_perechi(B,n)
    print(rb)
    
    a_=f.intersectie(A,B)
    b_=f.reuniune(A,B)
    c_=f.produs_boolean(A,B)
    bp=f.produs_boolean(B,B)
    d_=f.produs_boolean(bp,B)
    e=f.reuniune(B,bp)
    f_=f.reuniune(e,d_)
    print("a_",a_)
    print("b_",b_)
    print("c_",c_)
    print("d_",d_)
    print("e_",f_)


if __name__=="__main__":
    main()
