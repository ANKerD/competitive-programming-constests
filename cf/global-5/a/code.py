n = int(input())
a = []
for _ in range(n):
  a.append(int(input()))
b = [i // 2 for i in a]
c = sum(b)
if c < 0:
  for i in range(n):
    if abs(a[i]) % 2 == 0:
      continue
    if a[i] != 0:
      b[i] += 1
      c += 1
    if c == 0:
      break
# print('foo', sum(b))
assert(sum(b) >= 0)
for i in b:
  print(i)