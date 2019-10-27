t = int(raw_input())
for zetta in xrange(t):
    n = int(raw_input())
    a = raw_input().split()
    b = raw_input().split()
    r = []
    for i in xrange(n):
        p = 0
        m = 0
        for j in b[i]:
            if j == 'P':
                p += 1
            if j == 'M':
                m += 1
        t = len(b[i])-m
        if p*4 < t*3:
            r.append(a[i])
    print ' '.join(r)