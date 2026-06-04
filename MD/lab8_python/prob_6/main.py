import functii as f
from functools import reduce
import math

def main():
    
    a=f.citire()

    b=list(map(lambda x:x*9/5+32,a))
    print(b)
    
    c=reduce(lambda x ,y:(x+y),a)
    print(c/len(a))
    
    l=list(map(lambda x:math.floor(x),b))
    print(l)
    ad=list(map(lambda x :math.ceil(x),list(b)))
    print(ad)
    

if __name__=="__main__":
    main()
