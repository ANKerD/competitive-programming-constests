a = map(int, list(raw_input()))
b = map(int, list(raw_input()))
c = [ a[i] ^ b[i] for i in xrange(len(a))]
print ''.join(map(str, c))
