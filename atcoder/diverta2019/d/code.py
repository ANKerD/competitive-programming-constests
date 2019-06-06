from math import sqrt 

n = int(input())

x = int(sqrt(n))
if n == 2:
    print(0)
    exit()
ans = n-1
for i in range(2, x+1):
    y = dt = n//i
    while n//dt == n//y and n%y <= n//y:
        if n//y == n%y:
            ans += y
            break
        y -= 1
        if y == 1:
            break
        # print x,y,ans
print(ans)