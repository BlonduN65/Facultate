def subpunctul_a(A,B,C,U):
    
    not_A=U-A
    exp_1=A&(B|not_A )
    exp_2=B&A
    if exp_1 and exp_2:
        print("True")
    else:
        print("False")

def subpunctul_b(A,B,C,U):
    exp_1=(A-B)-C
    exp_2=(A-C)-B
    if exp_1 and exp_2:
        print("True")
    else:
        print("False")

def subpunctul_c(A,B,C,U):
    exp_1=(A-B)-C
    exp_2=(A-C)-(B-C)
    if exp_1 and exp_2:
        print("True")
    else:
        print("False")

def subpunctul_d(A,B,C,U):
    exp_1=(A&B)|A
    exp_2=A&B
    if exp_1 and exp_2:
        print("True")
    else:
        print("False")