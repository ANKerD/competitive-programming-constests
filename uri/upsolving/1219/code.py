from math import sqrt, pi
while True:
	try:
		a, b, c = map(int, raw_input().split())
		p = (a+b+c)/2.0
		v = sqrt(p*(p-a)*(p-b)*(p-c))
		s = a*b*c / sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))
		s = s*s*pi
		r = v/p
		r = r*r*pi
		print '%.4f %.4f %.4f' % (s-v, v-r, r)
	except Exception as e:
		break
