# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# l = raw_input().split()
# n = int(raw_input())
s = raw_input()
x = 0

for i in s:
    if i == 'a':
        x+=1
print(min(2*x-1, len(s)))
