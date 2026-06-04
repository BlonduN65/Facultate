import functii as f


def main():
    reuniune={1,2,3,4,5}
    intersectie={3,4}
    dif_AB={1}

    A=set()
    B=set()

    for x in reuniune:

        if x in dif_AB:
            A.add(x)
        elif x in intersectie:
            A.add(x)
            B.add(x)
        else:
            B.add(x)

    print("A=",A)
    print("B=",B)
if __name__=="__main__":
    main()