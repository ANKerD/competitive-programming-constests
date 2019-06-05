# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
def get(n):
    p = x = t = 0
    for i in xrange(n):
        a = raw_input()
        if a == 'M':
            continue
        elif a == 'X':
            p += 10
            t += 1
            x += 1
        elif a == '10':
            p += 10
            t += 1
        else:
            p += int(a)
    return p, x, t
n = int(raw_input())
p1, x1, t1 = get(n)
p2, x2, t2 = get(n)
ans = ""
if p1 > p2:
    ans = 'Yuju'
elif p1 < p2:
    ans = 'Yerin'
else:
    if t1 > t2:
        ans = 'Yuju'
    elif t1 < t2:
        ans = 'Yerin'
    else:
        if x1 > x2:
            ans = 'Yuju'
        elif x1 < x2:
            ans = 'Yerin'
        else:
            ans = 'Shoot-off'
print ans
