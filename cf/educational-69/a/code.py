# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
for i in xrange(n):
    n = int(raw_input())
    m = map(int, raw_input().split())
    m.sort(reverse=True)
    sz = min(m[0], m[1])
    # m = m[]
    print min(n-2, sz-1)