from functools import reduce
import functii as f


def main():

    x=f.citire_vector()
    y=f.citire_vector()

    s=list(map(lambda x,y: x+y,x,y))
    p=list(map(lambda x,y:x*y,x,y))
    ps=reduce(lambda x,y:x+y,p)

    print(s)
    print(p)
    print(ps)

if __name__=="__main__":
    main()
