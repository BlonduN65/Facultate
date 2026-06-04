def multime_biti(U,submultime):
    U_list=sorted(list(U))
    bitmask=0
    for i in range(len(U_list)):
        if U_list[i] in submultime:
            bitmask |=(1<<i)

    return bitmask


def biti_la_multime(U,bitmask):
    U_list=sorted(list(U))
    rezultat=set()
    for i in range(len(U_list)):
        if(bitmask >> i) &1:
            rezultat.add(U_list[i])

    return rezultat

