while True:
    n = int(raw_input())
    if n == 0:
        break
    mi = 10**88
    for i in xrange(n):
        a,b,c = raw_input().split()
        b = int(b)
        c = int(c)
        if b-c < mi:
            mi = b-c
            ans = a
    print ans