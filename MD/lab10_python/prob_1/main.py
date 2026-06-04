import functii as f
import math

def main():

   A={0,1,2,3,4}
   B={0,1,2,3}

   sub_a=f.genereaza_relatie(A,B,lambda x,y:x==y)
   print("Subpunctul a:",sub_a)

   sub_b=f.genereaza_relatie(A,B,lambda x ,y:x+y==4)
   print("Subpunctul b): ",sub_b)

   sub_c=f.genereaza_relatie(A,B,lambda x,y:x>y)
   print("Subpunctul c:",sub_c)

   sub_d=f.genereaza_relatie(A,B,lambda x,y:x|y)
   print("d:",sub_d)

   sub_e=f.genereaza_relatie(A,B,lambda x ,y:math.gcd(x,y)==1)
   print("e:",sub_e)

   sub_f=f.genereaza_relatie(A,B,lambda x,y:math.lcm(x,y)==2)
   print("f:",sub_f)
if __name__=="__main__":
    main()
