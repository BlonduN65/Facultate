def valoare_polinom(coef,n,x):
    if n==0:
        return coef[0]
    
    return valoare_polinom(coef,n-1,x)*x+coef[n]

def citire_vector(n):
    v=[]
    for i in range(n):
        x=int(input(f"v[{i}]="))
        v.append(x)
    return v
def afisare_vector(v,n):

    for i in range(n):
        print(v[i],end=" ")

def produs_scalar(v1,v2,n):
    if n==0:
        return v1[0]*v2[0]
    return produs_scalar(v1,v2,n-1)+v1[n]*v2[n]

def nr_negative(v,n):
    if n==0:
        if v[0]<0:
            return 1
        else:
            return 0
        
    if(v[n]<0):
            return nr_negative(v,n-1)+1 
    else:
            return nr_negative(v,n-1)   
    
def produs_elemente(v,n):
    if n==0:
        return v[0]
    return produs_elemente(v,n-1)*v[n]

def suma_elemente(v,n):
    if n==0:
        return v[0]
    return suma_elemente(v,n-1)+v[n]

def produs_elemente_negative(v,n):
    if(n==0):
        if v[0]<0:
            return v[0]
        else:
            return 0
    if v[n]<0:
        return produs_elemente_negative(v,n-1)*v[n]
    else:
      return   produs_elemente_negative(v,n-1)
    
def valoarea_minima(v,n):
    if n==0:
        return v[0]
    else:
            min_sir=valoarea_minima(v,n-1)
            if v[n]<min_sir:
                return v[n]
            else:
                return min_sir
            
def valoarea_maxima(v,n):
    if n==0:
        return v[0]
    else:
            max_sir=valoarea_maxima(v,n-1)
            if v[n]>max_sir:
                return v[n]
            else:
                return max_sir
def prob_3(v,n):
    print("numărul de elemente negative este:")
    print(nr_negative(v,n))
    print("produsul elementelor negative este:")
    print(produs_elemente_negative(v,n))
    print("suma elementelor este:")
    print(suma_elemente(v,n))             
    print("produsul elementelor este:")
    print(produs_elemente(v,n))
    print("valoarea minima este:")
    print(valoarea_minima(v,n))
    print("valoarea maxima este:")  
    print(valoarea_maxima(v,n))

def cmmdc_rec(a,b):
    if b==0:
        return a
    return cmmdc_rec(b,a%b)

def cmmdc_vector(v,n):
    if(n==0):
        return v[0]
    return cmmdc_rec(v[n],cmmdc_rec(v[n-1],cmmdc_vector(v,n-1)))
