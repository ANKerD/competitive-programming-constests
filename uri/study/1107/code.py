while True:
    try:
        n,m = map(int, raw_input().split())
        if n+m == 0: break
        a = map(int, raw_input().split())
        ans = n-a[0]
        for i in xrange(1,m):
            if a[i] < a[i-1]:
                ans += a[i-1]-a[i]
        print ans
    except Exception as e:
        print e
        break