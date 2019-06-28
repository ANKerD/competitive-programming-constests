# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
n = int(raw_input())
s = raw_input()
ans = 10 ** 100100
mid = n/2
while mid < n:
    if s[mid] != '0':
        break
    mid += 1
ans = min(ans, int('0'+s[:mid])+int('0'+s[mid:]))
mid = n/2+1
while mid < n:
    if s[mid] != '0':
        break
    mid += 1
ans = min(ans, int('0'+s[:mid])+int('0'+s[mid:]))
mid = n/2
while mid >= 0:
    if s[mid] != '0':
        break
    mid -= 1
if mid >= 0:
    ans = min(ans, int('0'+s[:mid])+int('0'+s[mid:]))
print ans