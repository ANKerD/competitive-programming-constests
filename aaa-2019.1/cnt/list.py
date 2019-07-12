i = 1
while True:
	try:
		a = raw_input()
		print '%d. %s' % (i, a)
	except:
		break
	i += 1
