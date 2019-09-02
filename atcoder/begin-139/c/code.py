n = int(raw_input())
m = map(int, raw_input().split())
a = [1 for i in xrange(n)]
ans = 0
for i in xrange(n):
  if i > 0 and m[i] <= m[i-1]:
    a[i] += a[i-1]
  ans = max(ans, a[i])
print ans-1
