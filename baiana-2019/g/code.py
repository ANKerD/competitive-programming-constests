from collections import defaultdict
f = defaultdict(int)

ans = map(lambda x: abs(int(x)) + 300, raw_input().split())
n = int(raw_input())

for i in range(n):
    m = raw_input().split()
    m = map(lambda x: abs(int(x)) + 300, m[1:])
    # print m, ans
    cur = 0
    for j in m:
        if j in ans:
            cur += 1
    f[cur] += 1

print "%d %d %d" % (f[6], f[5], f[4])