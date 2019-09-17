a = raw_input()
h = 'hello'
j = 0
for i in xrange(len(a)):
    if a[i] == h[j]:
        j += 1
        if j == 5:
            break
if j == 5:
    print 'YES'
else:
    print 'NO'