n = int(raw_input())
a = [1]
while a[-1] < n:
  b = a[:]
  for i in b:
    a.append(10*i)
    a.append(10*i+1)
  a = list(set(a))
a = filter(lambda x: x <= n, a)
print len(a)
