a, b, c = map(int, raw_input().split())
res = (a+b)/c
deb = (a+b)/c - a/c - b/c
a %= c
b %= c
dt = 0
if deb:
    dt = c-max(a,b)
print res,dt