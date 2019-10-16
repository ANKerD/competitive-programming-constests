maxn = 10 ** 5 + 10
st = [0] * maxn

def update(i, v):
  while i < maxn:
    st[i] += v
    i += i & -i

def query(i):
  ans = 0
  while i > 0:
    ans += st[i]
    i -= i & -i
  return ans

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
go = {}
for i in range(n):
  go[a[i]] = i+1
for i in range(n):
  b[i] = go[b[i]]
for i in range(n):
  update(i+1, 1)
ans = 0
for i in range(n):
  update(b[i], -1)
  # print(query(b[i]), i)
  if query(b[i]) > 0:
    ans += 1
print(ans)