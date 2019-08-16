from collections import defaultdict
b = defaultdict(int)
n = int(raw_input())
a = []
for i in xrange(n):
    x = list(raw_input())
    x.sort()
    a.append(''.join(x))
i = 0
ans = 0
for i in a:
    b[i] += 1
for i in b.values():
    ans += i*(i-1)/2
print ans