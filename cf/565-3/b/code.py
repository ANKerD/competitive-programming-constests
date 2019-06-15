# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
t = int(raw_input())
for i in xrange(t):
	n = int(raw_input())
	m = map(int, raw_input().split())
	r = [0,0,0]
	for j in m:
		r[j%3] += 1
	ans = r[0]

	z = min(r[1],r[2])
	r[1] -= z
	r[2] -= z
	ans += z

	ans += r[2] / 3
	ans += r[1] / 3
	print ans
