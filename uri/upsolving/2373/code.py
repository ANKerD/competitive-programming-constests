n = int(raw_input())
ans = 0
for _ in xrange(n):
    a,b = map(int, raw_input().split())
    if a > b:
        ans += b
print ans