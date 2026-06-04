def citire_vector():
    vec=[]
    n=int(input("Numarul de elemente ale vectorului este: "))
    for i in range(n):
        el=int(input(f"v[{i}]"))
        vec.append(el)
    return vec
    

