a = int(input())
m = list(map(int, input().split()))
if a <= min(m):
    print('S')
else:
    print('N')
