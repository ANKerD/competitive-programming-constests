while True:
  try:
    n = int(raw_input())
    a = []
    for _ in xrange(n):
      a.append(float(raw_input()))
    a.sort(key=lambda x: float(x))
    print '%.2f' % a[0]
  except:
    break