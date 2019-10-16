maxn = 3 * 10 ** 5 + 10
dp = [-1] * maxn
n = int(input())
a = list(map(int, input().split()))
b = a[:]
for i in b: a.append(i)
for i in b: a.append(i)

def solve(i):
  if dp[i] != -1:
    return dp[i]
  dp[i] = 1
  if a[(i+1) % n] / 2 < a[i]:
    pass
  else:
    dp[i] += solve(i+1 % n)
  return dp[i]

cycle = True
for i in range(n):
  if max(a) / 2 < min(a):
    cycle = False
    break
if cycle:
  print(' '.join(['-1'] * n))
  exit()
ans = [str(solve(i)) for i in range(n)]
print(' '.join(ans))