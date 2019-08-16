def get(a,b):
    ans = 0
    for i in xrange(min(len(a), len(b))):
        if a[i] == b[i]:
            ans += 1
    return ans

n = int(raw_input())
for x in xrange(1,n+1):
    a = raw_input()
    b = raw_input()
    c = raw_input()
    # if x == 13:
    #     print a,b,c
    print 'Instancia %d' % x
    if get(a,b) == get(a,c):
        if b == c:
            print 'empate'
        else:
            br = False
            for i in xrange(len(b)):
                if a[i] != b[i] and a[i] == c[i]:
                    print 'time 2'
                    br = True
                    break
                elif a[i] != c[i] and a[i] == b[i]:
                    print 'time 1'
                    br = True
                    break
            if not br:
                print 'empate'
    elif get(a,b) > get(a,c):
        print 'time 1'
    else:
        print 'time 2'
    # if x != n:
    print ''