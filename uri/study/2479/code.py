n = int(raw_input())
p = 0
m = []
for i in xrange(n):
    a,b = raw_input().split()
    if a == '+':
        p+=1
    m.append(b)
m.sort()
for i in m:
    print i
print 'Se comportaram: %d | Nao se comportaram: %d' % (p,n-p)