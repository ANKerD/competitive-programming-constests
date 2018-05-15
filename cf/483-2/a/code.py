# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
m = map(int, raw_input().split())
m.sort()
print m[(n-1)/2]
