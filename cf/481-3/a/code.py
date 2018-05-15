n = int(raw_input())
m = map(int, raw_input().split())
# s = raw_input()
# a, b, c = map(int, raw_input().split())
ans = {}
for i in xrange(len(m)):
    ans[m[i]] = i
a = [-1 for i in xrange(n)]
for i in ans:
    a[ans[i]] = i
for i in xrange(n-1,-1,-1):
    if a[i] == -1:
        a.pop(i)
print len(ans)
# print a
print ' '.join(map(str, a))
