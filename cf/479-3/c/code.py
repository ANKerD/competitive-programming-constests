def solve(taken, i, size):


n, k = map(int, raw_input().split())

taken = [False for i in xrange(256)]

m = map(int, raw_input().split())
f = [0 for i in xrange(256)]

for i in m:
    f[i] += 1
