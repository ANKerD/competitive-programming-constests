n,m = map(int, input().split())
c = {}
for i in range(n):
    a, b = input().split()
    c[a] = int(b)
i = 0

while i < m:
    r = input()
    ans = 0
    while r != '.':
        for j in r.split():
            if j in c:
                ans += c[j]
        r = input()
    print(ans)

    i+=1
pass