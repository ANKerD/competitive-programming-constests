maxn = 10**5 + 10

n = int(input())
m = list(map(int, input().split()))

f = [0 for i in range(maxn)]
g = [set() for i in range(maxn)]

ans = 1

known = set()

for j in range(n):
    i = m[j]
    
    if i not in known:
        known.add(i)
        f[i] = 0
        g[f[i]].add(i)
    
    g[f[i]].remove(i)
    f[i] += 1
    g[f[i]].add(i)

    # print(len(g[f[i]-1]), (f[i]-1), len(g[f[i]]) , j)
    if f[i]-1 > 0 and len(g[f[i]-1])*(f[i]-1) + len(g[f[i]]) == j:
        ans = j+1

    if j+1 < n and len(g[f[i]])*f[i] == j+1:
        ans = j+2

    if len(g[f[i]]) == j+1:
        ans = j+1

    if len(g[f[i]+1]) == 1 and len(g[f[i]])*f[i] + f[i] == j:
        ans = j+1

    if len(g[f[i]])*f[i] == j:
        ans = j+1

    # if len(g[f[i]+1]) == 1 and len(g[f[i]])*f[i] == j:
    #     ans = j+1

print(ans)