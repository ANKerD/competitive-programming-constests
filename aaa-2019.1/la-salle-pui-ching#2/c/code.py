def match(a,b):
	j = len(b)
	ans = 0
	for i in xrange(len(a)-j+1):
		# for j in xrange(len(b)):
		if a[i:i+j] == b:
			ans += 1
	return ans

s = raw_input()
a = match(s, "LSC")
b = match(s, "PCMS")
if a==b:
	print 'Tie'
elif a > b:
	print 'LSC'
else:
	print 'PCMS'