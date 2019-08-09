n = int(raw_input())
m = map(int, raw_input().split())
i = 1
while i < n and m[i-1] < m[i]: 
    i+=1
while i < n and m[i-1] > m[i]: 
    i+=1
if i == n:
    print 'YES'
else:
    print 'NO'