def verifica_argument(U):
    constantean=[1,0,1,0,0,0]
    vazut_marea=[0,1,0,1,1,1]
    
    distanta_mica=[]
    for i in range(len(U)):
        if constantean[i]==1:
            distanta_mica.append(1)
        else:
            distanta_mica.append(0)
    concluzie_valida=False
    for i in range(len(U)):
        if vazut_marea[i]==0 and distanta_mica[i]==1:
            concluzie_valida=True
            print(f"Argument validat de:{U[i]}")
            break

    print (concluzie_valida)
