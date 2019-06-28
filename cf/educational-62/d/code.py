n = int(raw_input())
ans = 6
for i in xrange(3,n):
    ans += i*(i+1)
print '%d' % ans