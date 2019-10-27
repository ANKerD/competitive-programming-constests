u = int(raw_input())
for _ in xrange(u):
  n = raw_input()
  a = [n[2:4], n[5:8], n[11:]]
  b = 0
  for i in a:
    x = ''
    for j in i:
      if j.isdigit():
        x += j
    b += int(x)
  print b