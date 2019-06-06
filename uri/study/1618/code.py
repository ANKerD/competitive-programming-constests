n = int(raw_input())
for z in xrange(n):
    m = map(int, raw_input().split())
    a = []
    x1 = y1 = 10**90
    x2 = y2 = -10**90
    # print x1,x2,y1,y2
    for i in xrange(0, 8, 2):
        x1 = min(x1, m[i])
        x2 = max(x2, m[i])
        
        y1 = min(y1, m[i+1])
        y2 = max(y2, m[i+1])
    
    y = m[-1]
    x = m[-2]

    if x1 < x < x2 and y1 < y < y2:
        print 1
    else:
        print 0