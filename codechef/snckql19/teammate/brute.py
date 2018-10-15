n = 10 ** 5

mod = 10 ** 9 + 7
res = 1

for i in xrange(1, n, 2):
    res = (res * i) % mod

print res

