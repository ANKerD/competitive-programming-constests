from collections import defaultdict
n, m = map(int, raw_input().split())
nn = map(int, raw_input().split())
mm = map(int, raw_input().split())

np = defaultdict(set)
mp = defaultdict(set)

for i in xrange(0, 2*n, 2):
    np[nn[i]].add(nn[i+1])
    np[nn[i+1]].add(nn[i])

for i in xrange(0, 2*n, 2):
    mp[mm[i]].add(mm[i+1])
    mp[mm[i+1]].add(mm[i])

s = []

for i in xrange(1, 10):
    if len(mp[i]) == 1:
        for j in mp[i]:
            if len(np[j]) == 0:
                s.append(i)
            break
if len(s) == 0:
    print -1
elif len(s) > 1:
    print 0
else:
    print s[0]
