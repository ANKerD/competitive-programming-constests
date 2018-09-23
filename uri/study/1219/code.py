while True:
	try:
		a, b, c = map(int, raw_input().split())
		p = a+b+c/2
		rad = max(a,b,c)
	except Exception as e:
		break
