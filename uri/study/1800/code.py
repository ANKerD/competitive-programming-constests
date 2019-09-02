q,e = map(int, raw_input().split())
vis = set(raw_input().split())
for i in xrange(q):
  a = raw_input()
  if a in vis:
    print 0
  else:
    print 1
  vis.add(a)
