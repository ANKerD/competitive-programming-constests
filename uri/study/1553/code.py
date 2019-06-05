while True:
    n,m = map(int, raw_input().split())
    if n+m==0:break
    a = map(int, raw_input().split())
    f = dict()
    ans = 0
    for i in a:
        if i not in f:
            f[i] =0
        f[i] += 1
        if f[i] == m:
            ans += 1
    print ans