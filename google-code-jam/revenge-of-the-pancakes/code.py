flip = lambda x: list(map(lambda y: '-' if y == '+' else '+', reversed(x)))
t = int(input())
for k in range(t):
  s = list(input())
  l = len(s)-1
  ans = 0
  while l >= 0:
    if s[l] == '+':
      l -= 1
      continue
    if s[0] == '+':
      i = 1
      while s[i] == '+':
        i += 1
      ans += 1
      rev = flip(s[:i])
      for j in range(i):
        s[j] = rev[j]
    i = 0
    while i <= l and s[i] == '-':
        i += 1
    ans += 1
    rev = flip(s[:i])
    for j in range(i):
      s[j] = rev[j]
  print('Case #%d: %d' % (k+1, ans))