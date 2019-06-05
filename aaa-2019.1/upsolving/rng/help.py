v = raw_input()
print v
v = map(int, v.split())
def get(x):
	return v[0]*x**3 + v[1]*x**2 + v[2]*x + v[3]

seed = v[5]
a = []
for i in xrange(15):
	a.append(seed)
	seed = get(seed) % v[4]
print a
