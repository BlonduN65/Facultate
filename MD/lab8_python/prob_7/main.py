
import functii as f
from functools import reduce



def main():

    inventory=f.citire()
    print(list(inventory))
    
    pret=list(map(lambda x:x["pret"]*x["stoc"],inventory))
    valori_stoc=reduce(lambda x,y:x+y,pret)
    print(valori_stoc)


if __name__=="__main__":
    main()
