# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
for i in xrange(n-1):
  a = []
  for j in xrange(n-1-i):
    a.append(j+1)
  print ' '.join(map(str, a))
