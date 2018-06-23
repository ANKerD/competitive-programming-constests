# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
a, b = map(int, raw_input().split())
m = map(int, raw_input().split())
p = 1
s = 0
cnt = 0
for i in xrange(a):
    p *= m[i]
    s += m[i]
    print p, s
    if s != 0 and p/s == b:
        cnt += 1
print cnt
