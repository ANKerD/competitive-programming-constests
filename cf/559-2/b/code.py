from random import randint

def test(i):
    # print i
    ans = 10**10
    for j in xrange(n):
        if i != j:
            ans = min(ans, min(m[j], m[i])/abs(j-i))
    return ans

n = int(raw_input())
m = map(int, raw_input().split())
mini = 0
maxi = 0
for i in xrange(n):
    if m[i] < m[mini]:
        mini = i
    if m[i] > m[maxi]:
        maxi = i

ans = min(test(mini), test(maxi), test(0), test(n-1))

for x in xrange(10):
    ans = min(ans, test(randint(1,n-1)))

print ans
