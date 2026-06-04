import functii as f

def main():
        print("%10s %10s %10s %10s %10s %10s " % ("b", "f", "s", "expr1", "expr2", "expr3"))
        for b in (True , False):
           for fs in (True , False):
                for s in (True , False):
                     expr1=s and (not fs)
                     expr2=f.implicatie(b,fs)
                     expr3=(not fs) and (b or s)
                     if expr1 and expr2 and expr3:
                        print(" solutieeee %10s %10s %10s %10s %10s %10s " % (b, fs, s, expr1, expr2, expr3))
                     else:
                        print("%10s %10s %10s %10s %10s %10s " % (b, fs, s, expr1, expr2, expr3))


if __name__ == "__main__":
     main()