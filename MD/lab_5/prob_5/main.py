import functii as f
import numpy as np

def main():

    U=['Ana','Maria','Ion','George']
    n=len(U)
    M=f.citire_matrice(n,"M")
    T=f.citire_matrice(n,"T")

    f.prop_a(M,T)
    f.prop_b(T,n)
    f.prop_c(M,T,n)
    f.prop_d(M,T,n)
    f.prop_e(M,T,n)
    f.prop_f1(M,n)
    f.prop_g(T,n)

if __name__=="__main__":
    main()
