# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
s = raw_input()
ok = True
c = 'bcdfghjklmnpqrstvwxyz'
v = 'aeiou'
for i in xrange(len(s)-1):
    if s[i] != 'n' and s[i] in c and s[i+1] not in v:
        ok = False
if s[-1] != 'n' and s[-1] in c:
    ok = False

if ok:
    print 'YES'
else:
    print 'NO'
