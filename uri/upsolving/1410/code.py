while True:
    n,m = map(int, raw_input().split())
    if n+m==0:break
    a = map(int, raw_input().split())
    b = map(int, raw_input().split())
    a.sort()
    b.sort(reverse=True)
    # print a,b
    if min(a) < b[-2]:
        print 'Y'
    else:
        print 'N'