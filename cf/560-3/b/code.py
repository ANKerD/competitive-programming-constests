# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
m = map(int, raw_input().split())
m.sort()

i = 0
k = 1
ans = 0
for i in xrange(n):
    if m[i] >= k:
        # print i, m[i], k
        k += 1
print k-1