while True:
    try:
        a = raw_input().split()
        t = 0
        i = 0
        while i < len(a):
            m = a[i][0].lower()
            i += 1
            x = 0
            while i < len(a) and a[i][0].lower() == m:
                i+=1
                x=1
            # print i
            t+=x
        print t
        # print '0000000000000000000000000000'
    except Exception as e:
        # print e
        break