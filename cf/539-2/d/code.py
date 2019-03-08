from collections import defaultdict

def palidrome(s):
    i = 0
    l = len(s)-1
    while i < l:
        if s[i] != s[l]:
            return False
        i+=1
        l+=-1
    return True

def solve(l, s):
	st = s[l:] + s[:l]
	return palidrome(st) and st != s

s = raw_input()
m = defaultdict(int)
for i in s:
    m[i]+=1

if len(m) == 1:
	print "Impossible"
	exit()
if len(m)%2 == 0:
	mid = len(s)/2
	if s[:mid] == s[(mid+1):]:
		m = defaultdict(int)
		for i in s[:mid]:
			m[i]+=1
		for i in s[(mid+1):]:
			m[i]+=1
		if len(m) == 1:
			print "Impossible"
			exit()
		
n = len(s)
for i in xrange(1, n):
    if solve(i, s):
        print 1
        exit()
print 2