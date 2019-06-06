k = 1
while k > 0:
    try:
            n = raw_input()
            if k > 1: print ''
            a = raw_input().split()
            f = m = 0
            for i in xrange(0, len(a), 2):
                if a[i] == n:
                    if a[i+1] == 'F':
                        f += 1
                    if a[i+1] == 'M':
                        m += 1
            
            print 'Caso %d:' % k
            print 'Pares Iguais: %d' % (f+m,)
            print 'F: %d' % f
            print 'M: %d' % m

            k+=1
    except:
        break
