from decimal import *
import fractions
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)
# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
for i in xrange(n):
    a, b, c = raw_input().split()
    a = int(a, int(c))
    b = int(b, int(c))

    if gcd(a, b) != 1:
        print 'Finite'
    else:
        print 'Infinite'
