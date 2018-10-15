# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
prim = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199]


# semiprimo = p * q
def semi(a):
    for i in prim:
        if a % i == 0 and a / i != i and a / i in prim:
            return True
    return False

def ok(a,b):
    return semi(a) and semi(b)

t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    ans = False
    for i in xrange(1, n/2 +1):
        if ok(i, n-i):
            ans = True
    if ans:
        print "YES"
    else:
        print "NO"