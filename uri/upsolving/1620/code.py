while True:
    a = raw_input()
    if a == '0':
        break
    a = float(a)
    x = (a-3)*2+3
    print '%.6f' % ((x-a)/a,)
