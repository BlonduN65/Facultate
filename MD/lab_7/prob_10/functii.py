def multime_putere(S):
    n=len(S)
    n_p=1 << n
    PS=[]

    for i in range(n_p):
        submultime_curenta=[]
        for j in range(n):
            if(i>>j)&1:
                submultime_curenta.append(S[j])
        PS.append(set(submultime_curenta))

    return PS