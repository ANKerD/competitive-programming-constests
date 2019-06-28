def compt(x,y):
    return -1 if x[1] > y[1] else 0

n,k = map(int, raw_input().split())
m = []
for i in xrange(n):
    x,y = map(int, raw_input().split())
    m.append((x,y))
m.sort(cmp=compt)

ans = 0
s = 0
l = 10**7
for i in xrange(k):
    x,y = m[i]
    s += x
    l = min(l,y)
    ans = max(ans, s*l)
m.reverse()
# aans = 0
s = 0
l = 10**7
for i in xrange(k):
    x,y = m[i]
    s += x
    l = min(l,y)
    ans = max(ans, s*l)
# print m, k
print ans