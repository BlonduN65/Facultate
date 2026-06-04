def implicatie(p,q):
    if p:
        return q
    else:
        return True
    

def echivalenta(p,q):
    if p==q:
        return True
    else:
        return False
    
def disjunctie(p,q):
    if p or q:
        return True
    else:
        return False
    
def conjunctie(p,q):
    if p and q:
        return True
    else:
        return False
    
