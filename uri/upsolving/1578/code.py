t = int(raw_input())
for i in xrange(t):
    n = int(raw_input())
    a = []
    for _ in xrange(n):
        a.append(map(lambda x: int(x)**2, raw_input().split()))
    col = [0 for _ in xrange(n)]
    for k in xrange(n):
        for j in xrange(n):
            col[j] = max(col[j], len(str(a[k][j])))
    print 'Quadrado da matriz #%d:' % (i+4)
    for k in xrange(n):
        b = []
        for j in xrange(n):
            b.append(' ' * (col[j]-len(str(a[k][j]))) + str(a[k][j]))
        print ' '.join(b)
    if i+1 < t:
        print ''