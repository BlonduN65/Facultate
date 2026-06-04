def citire():
    v=[]
    n=int(input("Numarul de valori:"))
    for i in range(n):
        el=int(input(f"v[{i}]"))
        v.append(el)

    return v
