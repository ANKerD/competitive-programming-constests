from math import sqrt

def gcd(a,b):
    if a == 0: return b
    return gcd(b%a,a)

def fact(n):
    a = set()

    for i in range(2, int(sqrt(n))+2):
        if n % i == 0:
            a.add(n//i)
            a.add(i)

    return a

maxn = 2*10 ** 6 + 10
p = [ True for i in range(maxn)]
f = [ maxn for i in range(maxn)]

i = 2
while i < maxn:
    f[i] = i
    j = i<<1
    while j < maxn:
        p[j] = False
        f[j] = min(f[j], i)
        j+=i
    i += 1
    while i < maxn and not p[i]:
        i+=1


t = int(input())
for z in range(t):
    n = int(input())
    m = list(map(int, input().split()))
    ans = m[0]
    mp = f[ans]
    for i in range(1,n):
        mp = min(mp, f[m[i]])
        ans = ans*m[i]//max(1,gcd(ans, m[i]))
    b = fact(ans)
    c = set(m)
    # print mp, ans, b
    while ans in c:
        ans *= mp
    print (ans)