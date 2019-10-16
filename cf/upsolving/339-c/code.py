s = raw_input()
n = int(raw_input())
a = []
for i in xrange(10):
  if s[i] == '1':
    a.append(i+1)
if n == 1:
  if len(a):
    print 'Yes'
    print a[0]
  else:
    print 'No'
else:
  if len(a) == 1:
    print 'No'
  else:
    print 'Yes'
    a = str(a[0]) + (' ' + str(a[1])) * (n-1)
    print a