# m = map(int, raw_input().split())
# a, b, c = map(int, raw_input().split())
# s = raw_input()
# l = raw_input().split()
n = int(raw_input())
for i in xrange(n):
	c = int(raw_input())
	cnt = 0
	while c % 2 == 0 or c % 3 == 0 or c % 5 == 0: 
		while c % 2 == 0:
			c/=2
			cnt += 1
		while c % 5 == 0:
			c = c/5*4
			cnt += 1
		while c % 3 == 0:
				c = c/3*2
				cnt += 1
	if c == 1:
		print cnt
	else:
		print -1
