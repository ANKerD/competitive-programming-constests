from collections import defaultdict
# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
s = defaultdict(int)
n = int(raw_input())

for i in xrange(n):
    a, b = map(int, raw_input().split())
    s[a] = b;

m = int(raw_input())
for i in xrange(m):
    a, b = map(int, raw_input().split())
    s[a] = max(s[a], b);
sum = 0
for i in s.values():
    sum += i
print sum
