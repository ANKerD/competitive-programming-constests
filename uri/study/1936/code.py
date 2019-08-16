from math import factorial
n = int(raw_input())
ans = 0
for i in range(10,0,-1):
    while n >= factorial(i):
        ans += 1
        n -= factorial(i)
print ans
