from math import log

while True:
    n = int(raw_input())
    if n == 0: break
    
    x = int(log(n,2))
    n-=1<<(x)
    print n,x
    print 2*n+1