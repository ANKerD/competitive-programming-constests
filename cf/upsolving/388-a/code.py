from collections import defaultdict
n = int(raw_input())
m = map(int, raw_input().split())
f = defaultdict(int)
for i in m:
  f[i] += 1
print max(f.values())