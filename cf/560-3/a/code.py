# m = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
a, b, c = map(int, raw_input().split())
n = raw_input()
# print n
n = n[::-1]
ans = 0
for i in xrange(b):
    if i == c:
        if n[i] == '0':
            ans += 1
    else:
        if n[i] == '1':
            ans += 1
print ans