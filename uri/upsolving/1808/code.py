a = raw_input()
i = 0
total = 0
cnt = 0.0
n = len(a)
old = 0
while i < n:
  if i+1 < n and a[i] == '1' and a[i+1] == '0':
    total += 10
    i += 1
  else:
    total += int(a[i])
  # print total-old
  # old = total
  cnt += 1
  i += 1
print '%.2f' % (total/cnt,)