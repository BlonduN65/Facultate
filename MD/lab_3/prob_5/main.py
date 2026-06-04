import functii as f

def main():

    print("%20s %14s %10s %10s %10s " % ("a","b","c","d","e"))
    for a in (True,False):
          for b in (True, False):
                for c in (True, False):
                      for d in (True, False):
                            for e in (True,False):
                                  expr1=f.implicatie(a,b)
                                  expr2=d or e
                                  expr3=f.xor(b,c)
                                  expr4=f.echivalenta(d,c)
                                  expr5=f.implicatie(e,a and d)
                                  if expr1 and expr2 and expr3 and expr4 and expr5:
                                       print("SOLUTIE: ", "%10d %14d %10d %10d %10d" % (a, b, c, d, e))


if __name__ == "__main__":  
        main()