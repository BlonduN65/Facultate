
def factorial(n):
    f=1
    for i in range(1,n+1):
        f=f*i
    return f    

def factorial_recursiv(n):
    if n==0:
        return 1
    else:
        return n*factorial_recursiv(n-1)
    
def ridicare_la_putere(x,n):
    p=1
    for i in range(1,n+1):
        p=p*x
    return p

def ridicare_la_putere_recursiv(x,n):
   if n==0:
         return 1
   else:
       return x*ridicare_la_putere_recursiv(x,n-1)


def fibonacci(n):
    a=0
    b=1
    for i in range(1,n+1):
        c=a+b
        a=b
        b=c
    return a

def fibonacci_recursiv(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fibonacci_recursiv(n-1)+fibonacci_recursiv(n-2)
    

def aranjamente(n,k):
    if k==0:
        return 1
    if k>n:
        return 0
    return (n-k+1)*aranjamente(n,k-1)


