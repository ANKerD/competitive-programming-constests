# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
a = raw_input()
b = raw_input()
if len(a) != len(b):
    print("NO")
    exit();
v = "aeiou"
for i in xrange(len(a)):
    if (a[i] in v) ^ (b[i] in v):
        print("NO")
        exit();
print("YES")