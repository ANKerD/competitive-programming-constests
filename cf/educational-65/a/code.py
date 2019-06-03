# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
t = int(raw_input())
for z in xrange(t):
    n = int(raw_input())
    s = raw_input()
    if n == 11 and s[0] == '8':
        print 'YES'
        continue
    while len(s) > 11 and s[0] != '8':
        s = s[1:]
    s = list(s)
    while len(s) > 11 and s[0] == '8':
        s.pop()
    if len(s) == 11 and s[0] == '8':
        print 'YES'
    else:
        print 'NO'
    

