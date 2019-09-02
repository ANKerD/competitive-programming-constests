a, b = map(int, raw_input().split())
if b == 1:
  print 0
else:
  x = a
  ans = 1
  while x < b:
    ans += 1
    x += a-1
  print ans