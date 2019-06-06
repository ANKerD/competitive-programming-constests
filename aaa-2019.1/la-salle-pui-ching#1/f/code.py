# import time
# from datetime import datetime

ld = [-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
# print(len(ld))

def nd(d, m, y):
    if d < 28:
        return d+1, m, y
    if d == 31 and m == 12:
        return 1, 1, y+1
    if (d == 28 and m == 2) and (y % 400 == 0 or y % 4 == 0 and y % 100 != 0):
        return 29, 2, y
    if d == 29 and m == 2:
        return 1, 3, y
    if d == ld[m]:
        return 1, m+1, y
    return d+1, m, y

d, m, y = map(int, input().split('/'))
d1, m1 = map(int, input().split('/'))
d2, m2 = map(int, input().split('/'))

ans = set()

d0, m0, y0 = d, m, y

for i in range(1, 2049):

    d0, m0, y0 = nd(d0, m0, y0)
    po = (d0, m0, y0)

    if m0 == m and d0 == d or m0 == m1 and d0 == d1 or m0 == m2 and d0 == d2 or i % 100 == 0:
        ans.add(po)
    pass
print(len(ans))