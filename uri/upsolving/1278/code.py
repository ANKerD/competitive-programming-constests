p = False
while True:
    n = int(raw_input())
    if n == 0: break
    if p: 
        print ''
    else: p = True
    sz = 0
    a = []
    for _ in xrange(n):
        i = raw_input().strip()
        while True:
            o = len(i)
            i = i.replace('  ', ' ')
            if o == len(i):
                break
        a.append(i)
        sz = max(sz, len(i))
    for i in a:
        # print i,i.replace('  ', ' ')
        print ' ' * (sz-len(i)) + i