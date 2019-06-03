from sys import stdout
v = [4, 8, 15, 16, 23, 42]
x = {}
for i in range(6):
    for j in range(i+1,6):
        if v[i]*v[j] in x:
            print v[i]*v[j], 'ero', v[i],v[j]
        x[v[i]*v[j]] = set([v[i],v[j]])

k = []
b = []
for i in range(4):
    print('? %d %d' % (i+1, i+2))
    stdout.flush()
    zet = int(raw_input())
    if zet == 0:
        exit()
    b.append(zet)
    k.append(x[zet])

a = [0 for i in range(6)]
for i in xrange(3):
    x = k[i].intersection(k[i+1])
    a[i+1] = next(iter(x))
# x = k[0].intersection(k[1])
a[0] = b[0]/a[1]
a[4] = b[3]/a[3]
a[5] = sum(v)-sum(a)
print '!', ' '.join(map(str,a))
stdout.flush() 
exit()