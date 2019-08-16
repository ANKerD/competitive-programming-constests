while True:
    try:
        n = int(raw_input())
        m = map(int, raw_input().split())
        for i in xrange(1,len(m)):
            m[i] += m[i-1]
        s = m[-1]
        for i in xrange(len(m)):
            m[i] *= 3
        ans = 0
        hp = set(m)
        # print sorted(hp)
        for i in xrange(n):
            # print m[i]+s,m[i]+2*s,
            if m[i]+s in hp and m[i]+2*s in hp:
                ans += 1

        print ans
    except EOFError:
        break
    except Exception as e:
        break
        print e