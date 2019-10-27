i = 0
while True:
    i +=1
    n,m = map(int, raw_input().split())
    if n+m == 0: break
    if m*27 < n:
        ans = 'impossible'
    else:
        ans = str(max(0,(n-1)/m))
    print 'Case %d: %s' % (i, ans)