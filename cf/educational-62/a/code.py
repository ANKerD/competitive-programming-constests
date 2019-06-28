n = int(raw_input())
m = map(int, raw_input().split())
m.append(0)
i = 0
ans = 0
while i <= n:
    t = m[i]
    while i+1 < t:
        i+=1
        t = max(t, m[i])
    i+=1
    ans += 1

print ans-1
