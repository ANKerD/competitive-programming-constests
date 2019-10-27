while True:
  n = int(raw_input())
  if n == 0: break
  a = {}
  for i in xrange(n):
    x, y = raw_input().split()
    a[x] = y
  ans = 0
  m = int(raw_input())
  for i in xrange(m):
    x, y = raw_input().split()
    diff = 0
    for i in xrange(len(a[x])):
      if a[x][i] != y[i]:
        diff+=1
        # break
    if diff > 1:
      ans += 1
  print ans