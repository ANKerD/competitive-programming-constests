while True:
  a = int(raw_input())
  if a == 0:
    print 0
    break
  ans = []
  while a:
    x = a % 32
    a /= 32
    if x < 10:
      ans.append(str(x))
      continue
    x -= 10
    ans.append(chr(65+x))
  print ''.join(reversed(ans))