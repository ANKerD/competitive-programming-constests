while True:
    n = int(raw_input())
    if n == 0: 
        break
    a = []
    for i in xrange(1, n+1):
        if i*i <= n:
            a.append(i*i)
        else:
            break
    print ' '.join(map(str,a))

    