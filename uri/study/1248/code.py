from collections import defaultdict

n = int(raw_input())

for z in xrange(n):
    m = defaultdict(int)
    for i in raw_input():
        m[i] += 1
    ch = False
    for i in raw_input():
        m[i] -=1
        if i not in m or m[i] < 0:
            ch = True
    for i in raw_input():
        m[i] -=1
        if i not in m or m[i] < 0:
            ch = True
    a = []
    if ch:
        print 'CHEATER'
    else: 
        for k,v in m.items():
            if v > 0:
                a.append(k)
        if len(a):
            a.sort()
            print ''.join(a)
        else:
            print ''