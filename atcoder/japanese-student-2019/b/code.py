n, k = map(int, raw_input().split())
a = map(int, raw_input().split())
gt = [0 for i in xrange(n)]
inv = [0 for i in xrange(n)]
for i in xrange(n):
  for j in xrange(i):
    if a[j] > a[i]:
      gt[i] += 1
  for j in xrange(i+1, n):
    if a[j] < a[i]:
      inv[i] += 1
ans = 0
mod = 10**9+7
if sum(inv) == 0:
  print 0
  exit()

for i in xrange(n):
  # ans += inv[i] + gt[i]
  ans += (k-1) * (n-gt[i])
  ans %= mod
print ans