n = int(raw_input())
m = map(int, raw_input().split())

for i in xrange(n):
    while m[i] % 2 == 0: m[i]/=2
    while m[i] % 3 == 0: m[i]/=3
a = set(m)
# print a, m
if(len(a)) == 1:
    print 'Yes'
else:
    print 'No'