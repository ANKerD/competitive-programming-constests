n = int(raw_input())
for i in xrange(n):
	a = raw_input().split('!');
	b = len(a)-1
	a = int(a[0]);
	j = b
	ans=a
	while a-j>0:
		ans*=(a-j)
		j+=b
	print ans
