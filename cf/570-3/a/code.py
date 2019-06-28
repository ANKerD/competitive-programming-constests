# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
while True:
    x = sum(map(int, list(str(n))))
    if x % 4 == 0:
        break
    n += 1
print n
