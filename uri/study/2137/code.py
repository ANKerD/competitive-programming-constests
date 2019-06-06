while True:
    try:
        n = int(raw_input())
        a = []
        for i in xrange(n):
            a.append(raw_input())
        a.sort()
        for i in a:
            print i
    except:
        break