# m = map(int, raw_input().split())
n,m = map(int, raw_input().split())
ans = 0
for i in xrange(1,n+1):
  for j in xrange(1,m+1):
    ten = j/10
    one = j%10
    if j < 22 or ten < 2 or one < 2:
      continue
    if j/10 * (j%10) == i:
      ans += 1
print ans
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
