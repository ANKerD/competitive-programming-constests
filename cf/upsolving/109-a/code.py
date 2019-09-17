n = int(raw_input())
for i in xrange(n+1, -1, -1):
  if (n - 7*i) >= 0 and (n - 7*i) % 4 == 0:
    print '4' * ((n - 7*i) / 4) + '7' * i
    exit()
print -1
