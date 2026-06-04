import functii as f


def main():

    U=f.citire_multimi()
    A=f.citire_multimi()
    B=f.citire_multimi()
    C=f.citire_multimi()

    bit_A=f.multime_biti(U,A)
    bit_B=f.multime_biti(U,B)
    bit_C=f.multime_biti(U,C)

    masca_U=(1<<len(U))-1

    bit_C_complement=bit_C^masca_U
    print(f"C in complement binar:{bit_C_complement:010b}")

    bit_reun=bit_A | bit_B
    print(f"Reuniune A si B: {bit_reun:010b}")

    bit_intersecte=bit_A & bit_B & bit_C
    print(f"Intersectie: {bit_intersecte:010b}")

    bit_dif=bit_B ^ ~bit_C
    print(f"Diferenta: {bit_dif:010b}")

if __name__=="__main__":
    main()