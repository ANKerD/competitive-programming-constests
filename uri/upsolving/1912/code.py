while True:
    n,m = map(int, raw_input().split())
    if n == m == 0: break
    a = map(int, raw_input().split())
    if sum(a) == m:
        print ':D'
        continue
    l = 0.0
    r = max(a)
    tt = 31
    while tt > 0:
        tt-=1
        mid = (l+r)/2
        t = 0

        for i in a:
            if i > mid:
                t += i-mid
        if abs(t-m) < 10 ** -5:
            ans = mid
            break
        if t > m:
            ans = mid
            l = mid
        else:
            r = mid
    print '%.4f' % ans