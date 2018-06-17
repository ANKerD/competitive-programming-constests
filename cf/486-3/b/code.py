# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
m = []
for i in xrange(n):
    m.append(raw_input())
m.sort(key=lambda x: len(x))
ans = 'YES'
for i in xrange(n-1):
    if m[i] not in m[i+1]:
        ans = 'NO'
        break
print ans
if(ans == 'YES'):
    for i in m:
        print i
