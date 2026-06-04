def suma_cifre(numar):
    if numar<10:
        return numar
    else:
        return int(numar%10)+suma_cifre(int(numar/10))

def produs_cifre(numar):
    if numar<10:
        return numar
    else:
        return int(numar%10)*produs_cifre(int(numar/10))