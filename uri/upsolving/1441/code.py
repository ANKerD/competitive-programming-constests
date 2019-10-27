while True:
    n = int(raw_input())
    if n == 0: break
    ans = n
    while n != 1:
        # print n, i
        if n % 2 == 0:
            n = n/2
        else:
            n = 3*n+1
        ans = max(ans, n)
    print ans