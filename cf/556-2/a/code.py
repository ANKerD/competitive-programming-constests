a,b,c = map(int, raw_input().split())
x = min(map(int, raw_input().split()))
y = max(map(int, raw_input().split()))
ans = c%x+max(c-(c%x), c/x*y)
print ans