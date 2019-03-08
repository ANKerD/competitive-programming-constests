n = 10 ** 2
v = [ (1+i) for i in xrange(n)]
print n
print ' '.join(map(str, reversed(v)))