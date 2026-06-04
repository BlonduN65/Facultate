def citire_vector():
    v=[]
    n=int(input("Dati numarul de elemente ale vectorului"))
    for i in range(n):
        el=int(input(f"v[{i}]"))
        v.append(el)

    return v
