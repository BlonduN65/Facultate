import functii as f
from functools import reduce


def main():

    a=f.citire()
    b=map(str.upper,a)
    c=reduce(lambda x,y:x+y,a)
    print(list(b))
    print(c)




if __name__=="__main__":
    main()
