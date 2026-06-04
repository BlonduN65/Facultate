import functii as f

def main():

    U=set(range(1,11))
    A={2,4,6,8,10}
    B={1,2,3,4}

    bit_A=f.multime_biti(U,A)
    bit_B=f.multime_biti(U,B)
    masca_univers=(1<<len(U))-1

    bit_complement_A=bit_A^masca_univers
    print(f"Binar Complement A: {bit_complement_A:010b}")

    bit_reuniune=bit_A|bit_B
    print(f"Reuniune Binar: {bit_reuniune:010b}")

    bit_intersectie=bit_A&bit_B
    print(f"Intersectia Binar: {bit_intersectie:010b}")

    bit_xor=bit_A^bit_B
    print(f"XOR Binar: {bit_xor:010b}")
    

    print(f"A pe biti: {bit_A:010b}")
    print(f"B pe biti: {bit_B:010b}")

if __name__=="__main__":
    main()