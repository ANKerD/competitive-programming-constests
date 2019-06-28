def cmp(a):
    return len(a)

n,k = map(int, raw_input().split())
s = raw_input()

a = set([s])
while True:
    odd = len(a)
    aux = set()
    for j in a:
        aux.add(j)
        for i in xrange(len(j)):
            if i < len(j) and j[0:i]+j[i+1:len(j)]:
                aux.add(j[0:i]+j[i+1:len(j)])
            else:
                aux.add(j[:len(j)-1])
    a = aux
    if len(a) == odd or len(a) >= k:
        break
a = list(a)
a.sort(key=cmp, reverse=True)
if len(a) < k:
    print -1
else:
    ans = 0
    for i in xrange(k):
        ans += n-len(a[i])
    print '%d' % ans