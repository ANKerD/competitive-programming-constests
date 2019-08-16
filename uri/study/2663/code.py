n = int(raw_input())
k = int(raw_input())
a = []
for i in xrange(n):
    a.append(int(raw_input()))
a.sort(reverse=True)
ans = k
# print a
for i in xrange(k,n):
    if a[i] == a[i-1]:
        ans = i+1
    else: break
print ans