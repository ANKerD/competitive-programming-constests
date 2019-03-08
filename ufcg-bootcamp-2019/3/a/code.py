# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
m = map(int, raw_input().split())

ans = 0
for i in range(n):
    for j in range(i+1,n):
        if i < m[j] and j < m[i]:
	    print i, j
            ans += 1
print ans
