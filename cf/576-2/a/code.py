# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n,x,y = map(int, raw_input().split())
a = map(int, raw_input().split())
rainy = a[0]
ans = -1
for i in xrange(n):
    swap = True
    for j in xrange(max(0, i-x), min(n, i+y+1)):
        # print i,j
        if i != j and a[i] >= a[j]:
            swap = False
            break
    if swap:
        ans = i
        # rainy = a[i]
        break
print ans+1