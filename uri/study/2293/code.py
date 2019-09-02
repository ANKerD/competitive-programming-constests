n,m = map(int, raw_input().split())
a = []
ans = 0
for i in xrange(n):
  a.append(map(int, raw_input().split()))
  ans = max(ans, sum(a[-1]))
for i in xrange(1, n):
  for j in xrange(m):
    a[i][j] += a[i-1][j]
    ans = max(a[i][j], ans)
print ans