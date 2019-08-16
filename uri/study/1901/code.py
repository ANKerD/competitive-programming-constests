n = int(raw_input())
a = []
for i in xrange(n):
    a.append(map(int, raw_input().split()))
ans = set()
for i in xrange(2*n):
    x,y = map(int, raw_input().split())
    x-=1
    y-=1
    ans.add(a[x][y])
print len(ans)