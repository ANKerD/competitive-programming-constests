# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
def is_palindrome(l, r):
    for i in xrange(r-l):
        if s[l + i] != s[r - i]:
            return False;
    return True;
s = raw_input()
t = len(s)-1
while t > 0:
    for i in xrange(len(s)-t):
        # print i, t
        if not is_palindrome(i, t+i):
            print t+1
            exit()
    t -=1
print 0
# l = raw_input().split()
# n = int(raw_input())
