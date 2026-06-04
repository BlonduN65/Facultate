from numpy import sqrt
import functii as f

def main():
    dom=list(range(-10,10))
    exp1=list(map(lambda x:x*x,dom))
    exp2=list(map(f.patrat,dom))
    exp3=list(map(lambda x ,y,z:x*x+3*y+5*z,dom,dom,dom))
    exp4=list(map(f.polinom,dom,dom,dom))
    print(exp1)
    print(exp2)
    print(exp3)
    print(exp4)

if __name__=="__main__":
    main()
