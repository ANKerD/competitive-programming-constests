def sv(i,n):
    t = 0.0
    a = {}
    while True:
        try:
            b = raw_input()
            # print b
            if not b: 
                break
            if not b in a:
                a[b] = 0
            t += 1
            a[b] += 1

        except Exception as e:
            break
    for key, value in sorted(a.items()):
        print '%s %.4f' % (key, value * 100 / t)
    if i+1 < n:
        print ''
            
n = int(raw_input())
raw_input()
for i in xrange(n):
    sv(i,n)
    # break