# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
# n = int(raw_input())
def names(s):
	s = s.split()
	r = []
	for i in s:
		r.append(name(s))
	return ', '.join(r)
def prop(s, v):
	if s[-1] == ',':
		s = s[:len(s)-1]
	s = s.split("=")
	v[s[0]] = s[1][1:(len(s[1])-1)]
	print v[s[0]]

t = int(raw_input())
for x in xrange(t):
	n = int(raw_input())
	for i in xrange(n):
		raw_input()
		np = {}
		for j in xrange(8):
			prop(raw_input(), np)
		print names(np['author'])
		raw_input()
