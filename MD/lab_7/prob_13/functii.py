def subpunctul_a(A):
    nr=0
    for e1 in A:
        for e2 in A:
            for e3 in A:
                for e4 in A:
                    for e5 in A:
                        for e6 in A:
                            nr+=1

    print("a):",nr)
    

def subpunctul_b(A):
    nr=0
    for e1 in A:
        for e2 in A:
            for e3 in A:
                for e4 in A:
                    for e5 in A:
                        for e6 in A:
                            if e1 =='a' or e1== 'c':
                                nr+=1

    print("b):",nr)



def subpunctul_c(A):
    nr=0
    for e1 in A:
        for e2 in A:
            for e3 in A:
                for e4 in A:
                    for e5 in A:
                        for e6 in A:
                            ok=0
                            if e2=='b' or e3=='b' or e4=='b' or e5=='b' or e6=='b':
                                ok+=1
                            if (e1 =='a' or e1== 'c') and ok!=0:
                                nr+=1

    print("c):",nr)


def subpunctul_d(A):
    nr=0
    for e1 in A:
        for e2 in A:
            for e3 in A:
                for e4 in A:
                    for e5 in A:
                        for e6 in A:
                            ok=0
                            if e2=='b' or e3=='b' or e4=='b' or e5=='b' or e6=='b' or e2=='d' or e3=='d' or e4=='d' or e5=='d' or e6=='d':
                                ok+=1
                            if (e1 =='a' or e1== 'c') and ok!=0:
                                nr+=1

    print("d):",nr)


def subpunctul_e(A):
    nr=0
    for e1 in A:
        for e2 in A:
            for e3 in A:
                for e4 in A:
                    for e5 in A:
                        for e6 in A:
                            ok1=False
                            ok2=False
                            if e2=='b' or e3=='b' or e4=='b' or e5=='b' or e6=='b' :
                                ok1=True
                            if  e2=='d' or e3=='d' or e4=='d' or e5=='d' or e6=='d':
                                ok2=True
                            if (e1 =='a' or e1== 'c') and ok1 and ok2:
                                nr+=1

    print("e):",nr)