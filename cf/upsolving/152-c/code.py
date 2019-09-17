n, m = map(int, raw_input().split())
a = [set() for i in xrange(m)]
for _ in xrange(n):
  inp = raw_input()
  for i in xrange(m):
    a[i].add(inp[i])
ans = 1
for i in xrange(m):
  ans *= len(a[i])
  ans %= 10 ** 9 + 7
print ans

