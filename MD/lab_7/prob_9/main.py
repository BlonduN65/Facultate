def main():
   
    intersectie={'g','i'}
    dif_AB={'b','e','h'}
    dif_BA={'a','m','f'}
    A=set()
    B=set()
    for x in dif_AB:
        A.add(x)
    for x in dif_BA:
        B.add(x)

    for x in intersectie:
        A.add(x)
        B.add(x)

    
    print("A=",sorted(A))
    print("B=",sorted(B))


if __name__=="__main__":
    main()