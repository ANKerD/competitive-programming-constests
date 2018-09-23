def form(a):
	a = str(a);
	while len(a) < 3:
		a = '0'+a
	return a
def cet(a):
	a = str(a);
	while len(a) < 2:
		a = '0'+a
	return a

while True:
	try:
		a = int(raw_input())
		b = int(raw_input())
		aa = []
		while(a > 0):
			aa.append(a % 1000)
			a/=1000
		aa.reverse()
		aa = ','.join(map(form, aa))
		# print aa[0]
		while len(aa) > 0 and aa[0] == '0':
			aa = aa[1:]
		# if len(aa) == 0:
		# 	aa='0'
		print '%s.%s' % ('$'+aa, cet(b))
	except EOFError:
		break
