
t = 0
while True:
    try:
        if t: print ''
        t=9
        a = raw_input()
        for i in xrange(len(a)):
            b = a[::-1]
            b = list(b[i:][::-1])
            print ' ' * i + ' '.join(b)
    except:
        break