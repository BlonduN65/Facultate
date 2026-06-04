import functii as f
import numpy as np

def main():


    U1=[]
    U1=np.arange(-10,11,1)
    U2=[]
    U2=np.arange(-100,101,1)
    U3=[]
    U3=np.arange(-10,10,0.1)
    
    f.subpunctul_a(U1,U2)
    f.subpunctul_b(U1,U2)
    f.subpunctul_c(U3)
    f.subpunctul_d(U3)






if __name__=="__main__":
        main()

