def citire_multimi():
    multime=set()
    n=int(input("Dati numarul de elemente ale multimii: "))

    for i in range(n):
        elem=(input("el:"))
        multime.add(elem)

    return multime

def multime_biti(U,A):
    U_list=sorted(list(U))
    mask=0
    for i in range(len(U)):
        if U_list[i] in A:
            mask|=(1<<i)

    return mask