# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
cnt = 0
n = int(raw_input())

if n >= 100:
    cnt += n/100
    n %= 100

if n >= 20:
    cnt += n/20
    n %= 20

if n >= 10:
    cnt += n/10
    n %= 10

if n >= 5:
    cnt += n/5
    n %= 5

if n >= 1:
    cnt += n/1
    n %= 1

print cnt
