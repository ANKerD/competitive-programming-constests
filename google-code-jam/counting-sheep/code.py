t = int(input())
for i in range(t):
  n = int(input())
  if n == 0:
    ans = 'INSOMNIA'
  else:
    numbers = set(map(str, range(10)))
    c = 0
    while len(numbers) > 0:
      c += n
      for num in str(c):
        numbers.discard(num)
    ans = str(c)
  print('Case #%d: %s' % (i+1, ans))