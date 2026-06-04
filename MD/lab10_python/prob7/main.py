import functii as f
import numpy as np


def main():

   A=f.citire_matrice()
   f.afisare(A)
   B=f.citire_matrice()
   f.afisare(B)
   C=f.citire_matrice()
   f.afisare(C)
   print("Subpunctul a):")
   f.afisare(f.intersectie(A,B))
   f.afisare(f.reuniune(A,B))
   f.afisare(f.diferenta(A,B))
   f.afisare(np.transpose(A))
   f.afisare(f.compunere(B,B))
   f.afisare(f.compunere(B,A))
   print("Subpunctul b):")
   f.afisare(f.intersectie(A,C))
   f.afisare(f.reuniune(C,B))
   f.afisare(f.diferenta(C,B))
   f.afisare(np.transpose(C))
   f.afisare( f.compunere(A,A))
   f.afisare(f.compunere(B,C))




if __name__=="__main__":
    main()
