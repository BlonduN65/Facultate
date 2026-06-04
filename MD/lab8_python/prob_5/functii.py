import sys
def citire():
    print("dati textul:") 
    text_complet=sys.stdin.read()
    lista_cuvinte=text_complet.split()

    return lista_cuvinte
