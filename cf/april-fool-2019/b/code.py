
from math import log

n = int(raw_input())
m = map(int, raw_input().split())
ans = 0
for i in m:
    if int(2**log(i,2)) == i:
        ans = max(ans, i)
print ans