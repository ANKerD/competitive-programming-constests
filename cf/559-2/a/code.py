n = int(raw_input())
s = raw_input()
st = 0
ans = 0
for j in range(n):
    i = s[j]
    if i == '-':
        ans -= 1
    else:
        ans += 1
    if ans < 0:
        st = min(st,ans)
print ans-st