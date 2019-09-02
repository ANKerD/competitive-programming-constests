from math import sqrt
n = int(raw_input())
m = []
for i in xrange(n):
  a, b = map(int, raw_input().split())
  m.append((a,b))

def get(i, j):
  x1,y1 = m[i]
  x2,y2 = m[j]
  t = (x1 + x2) ** 2 + (y1 + y2) ** 2
  # print m[i], m[j]
  return t

ans = 0
m.append((0,0))
for i in xrange(n):
  ans = max(ans, get(i, -1))
m.pop()
try:
  for _ in xrange(n):
    x = 0
    y = 1
    for i in xrange(n):
      for j in xrange(i+1, n):
        if max(i, j) >= len(m):
          continue
        if get(i, j) > get(x, y):
          x = i
          y = j
          ans = max(ans, get(x, y))
    # print ans
    # print m
    x1,y1 = m[x]
    x2,y2 = m[y]
    m.pop(y)
    m.pop(x)
    m.append((x1+x2, y1+y2))
except:
  m.append((0,0))
  ans = max(ans, get(0, -1))
  print '%.100f' % sqrt(ans)