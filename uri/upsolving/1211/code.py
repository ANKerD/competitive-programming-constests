while True:
    try:
        n = int(raw_input())
        # print t,'9090900909'
        t = 0

        sst = []

        for i in xrange(n):
            sst.append(raw_input())
        sst.sort()

        for i in xrange(n-1):
            a = sst[i]
            b = sst[i+1]
            for j in xrange(len(b)):
                if a[j:] == b[j:]:
                    break
                if a[j] == b[j]:
                    # print i,j
                    t += 1
                else:
                    break
            a = b
        print t

    except Exception as e: 
        # print e
        break