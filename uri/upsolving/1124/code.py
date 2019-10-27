while True:
    a,b,c,d = map(int, raw_input().split())
    if sum([a,b,c,d]) == 0:
        break
    x1 = y1 = c
    x2 = a-d
    y2 = b-d

    # print x1**2, y1**2, x2**2, y2**2, (a+b)**2
    # print x1,y1,x2,y2
    if (y1-y2)**2 + (x1-x2)**2 >= ((c+d))**2 and 2*max(c,d) <= min(a,b):
        print 'S'
    else:
        print 'N'