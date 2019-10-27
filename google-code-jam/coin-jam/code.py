maxn = 2 ** 22
def _bin(num, sz):
  ans = ''
  for i in range(sz-2):
    ans = ('1' if num & 1 else '0') + ans
    num >>= 1

  return '1' + ans + '1'

primes = []
p = [True for _ in range(maxn)]
p[0] = p[1] = False
i = 2
while i < maxn:
  primes.append(i)
  j = i+i
  while j < maxn:
    p[j] = False
    j += i
  i += 1
  while i < maxn and not p[i]:
    i += 1

def isok(n):
  for i in range(2, 11):
    x = int(n, i)
    if x < maxn:
      if p[x]:
        # print(n, 'deu ruim com', i, x)
        return False
    else:
      # print(n, i, x)
      isPrime = True
      j = 2
      for j in primes:
        if x % j == 0:
          isPrime =  False
          break
        if j * j > x: break
      if isPrime:
        # print(n, 'deu ruim com', i, x)
        return False
  return True

def div(n):
  i = 2
  while n % i:
    i += 1
  return i

t = int(input())
for foo in range(t):
  n, count = list(map(int, input().split()))
  i = -1
  print('Case #%d:' % (foo+1,))
  while count:
    i += 1
    cur = _bin(i, n)
    if not isok(cur): 
      # print('not', cur, i)
      continue
    ans = [cur]
    for j in range(2, 11):
      ans.append(str(div(int(cur, j))))
    print(' '.join(ans))
    count -= 1