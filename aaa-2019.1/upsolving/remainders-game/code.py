def gcd(a,b):
    if not a: return b
    return gcd(b%a,a)
def lcm(a,b):
    return a*b/gcd(a,b)

n, k = map(int, raw_input().split())
m = map(int, raw_input().split())
y = reduce(lambda x, y: gcd(k, lcm(x,y)), m, 1)
if y == k:
    print 'Yes'
else:
    print 'No'