# m = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())

a, b = map(int, raw_input().split())
if 2*b >= a or a == b:
    print (a - b)
else:
    print (max(1, b))