while True:
    n,m = map(int, raw_input().split())
    if n == 0: break
    a = 0
    for i in xrange(n):
        _,x = raw_input().split()
        a += int(x)
    for i in xrange(m+1) :
        if i*3 + (m-i)*2 == a:
            print m-i
            break