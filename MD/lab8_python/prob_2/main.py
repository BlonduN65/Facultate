from numpy import sqrt
import functii as f
def main():
    x=(3.13159,-23.2381,-123.123,24,-96,36,64,-23.-74,-121,34)

    val_poz=filter(f.pozitiv,x)
    rezultat=list(map(f.radical,val_poz))

    val_poz2=list(filter(lambda y:y>0,x))
    rezultat2=list(map(lambda y:sqrt(y),val_poz2))

    print(rezultat)
    print(rezultat2)



if __name__=="__main__":
    main()
