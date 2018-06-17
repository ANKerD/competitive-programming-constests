from sys import stdout
def fpow(a, b):
    if b == 0:
        return 1
    if b % 2 == 1:
        return a * fpow(a, b-1)
    return fpow(a*a, b/2)

q = int(raw_input())
for x in xrange(q):
    n = int(raw_input())
    b = map(int, raw_input().split())
    c = int(raw_input())
    i = 64
    # while fpow(n, i) >= c:
    #     i-=1
    ans = []
    while i > -1:
        if c > n:
            ans.append
    print ans
