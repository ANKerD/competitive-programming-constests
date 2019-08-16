while True:
    n = int(raw_input())
    if n == 0: break
    a = map(int, raw_input().split())
    if sum(a) == 0:
        print (n+1)/2
        continue
    i = 0
    while i < n:
        if a[i] != 0:
            break
        i += 1
    a = a[i:] + a[:i]
    ans = 0
    for i in xrange(n):
        if a[i] == a[i-1] == 0:
            a[i] = 1
            ans += 1
    print ans