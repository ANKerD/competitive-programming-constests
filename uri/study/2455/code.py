a,b,c,d = map(int, raw_input().split())

a,b = a*b,c*d
if a == b:
    print 0
if a < b:
    print 1
if a > b:
    print -1