# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()

def cmp(a, b):
    for i in xrange(3):
        if a[i] < b[i]:
            return -1
        if a[i] > b[i]:
            return 1
    return 0

n = int(raw_input())
a = []
for i in xrange(n):
    m = map(int, raw_input().split())
    m.sort()
    a.append(m)
a.sort(cmp=cmp)

ok = True

for i in xrange(1,n):
    for j in xrange(3):
        if a[i][j] <= a[i-1][j]:
            ok = False
            break
if ok:
    print 'S'
else:
    print 'N'