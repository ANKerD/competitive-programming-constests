def solve(k, a,b,c, x) :
    l = 1
    r = x
    ans = 0
    while l < r:
        mid = (l+r+1)/2
        # print k,l,r,mid,ans
        if mid == k:
            ans += c
            return ans
        if mid < k:
            ans -= b
            l = mid
        else:
            r = mid-1
            ans -= a
    return ans+c

def gcd(a,b):
    if a == 0: return b
    return gcd(b%a,a)

k,a,b,c = map(int, raw_input().split())

ans = 0

for i in xrange(k):
    ans += solve(i+1, a,b,c, k)
    # break

zet = gcd(ans, k)
a,b = ans/zet, k/zet
if b < 0:
    a,b=-a,-b
if a == 0:
    print '0/1'
    # print "aui"
else:
    print '%d/%d' % (a,b)