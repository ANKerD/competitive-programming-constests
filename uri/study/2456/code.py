m = map(int, raw_input().split())
hasinc = False
hasdec = False
for i in xrange(1, len(m)):
	if m[i] > m[i-1]:
		hasinc = True
	if m[i] < m[i-1]:
		hasdec = True
if   hasinc and not hasdec:
	print 'C'
elif hasdec and not hasinc:
	print 'D'
else:
	print 'N'