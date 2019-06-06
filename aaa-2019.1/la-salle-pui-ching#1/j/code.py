a, b = map(int, raw_input().split())
x1, y1 = map(int, raw_input().split())
x2, y2 = map(int, raw_input().split())

if (x1 <= a and y1 <= b) and x1+x2 <= a and max(y1,y2) <= b or y1+y2 <= b and max(x1,x2) <= a:
    print 'YES'
else:
    print 'NO'



if x1 <= a and y1 <= b:
    if x2 > a-2*x1 and y2 > b-2*y1:
        print 'YES'
    else:
        print 'NO'
else:
    if x2 <= a and y2 <= b:
        print 'NO'
    else:
        print 'YES'