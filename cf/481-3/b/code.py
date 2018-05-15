a = int(raw_input())
m = raw_input()
# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
ans = 0
for i in xrange(a-2):
    if m[i] == 'x' and m[i+1] == 'x' and m[i+2] == 'x':
        ans += 1
print ans
