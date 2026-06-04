def relatie(A):
    R=[]
    for a in A:
        for b in A:
            if a|b:
                R.append((a,b))

    return R
