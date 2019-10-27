while True:
    n = int(raw_input())
    if n == 0: break
    err = {}
    cn = ddp = 0
    sv = []
    for i in xrange(n):
        a, b, c = raw_input().split()
        b = int(b)
        if a in sv: continue
        if a not in err:
            err[a] = []
        if c == 'correct':
            sv.append(a)
            cn += 1
            ddp += 20 * len(err[a]) + sum(err[a]) + b
        else:
            err[a].append(0)
    print cn, ddp