# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# n = int(raw_input())

l = raw_input().split()
ans = []
for i in l:
    if len(i) > 3:
        if i[:2] == i[2:4]:
            i = i[2:]
    ans.append(i)
print ' '.join(ans)
