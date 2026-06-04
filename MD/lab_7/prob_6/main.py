import functii as f

def main():
    U={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
    A={1,2,3,8,10,12,13}
    B={2,4,5,6,7,8,11,14,15}
    C={4,9,10,11,13}

    print("a)")
    f.subpunctul_a(A,B,C,U)
    print("b)")
    f.subpunctul_b(A,B,C,U)
    print("c)")
    f.subpunctul_c(A,B,C,U)
    print("d)")
    f.subpunctul_d(A,B,C,U)


if __name__=="__main__":
    main()