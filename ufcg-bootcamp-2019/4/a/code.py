def mx(a,b):
	m1 = max(m1, a[0]*b[0])
	for i in a:
        for j in b:
                m1 = max(m1, i*j)
	return m1

n,m = map(int, raw_input().split())

a = map(int, raw_input().split())
b = map(int, raw_input().split())

mina = min(a)
maxa = max(a)
a.remove(mina)

m1 = mx(a,b)

a.remove(maxa)
a.append(mina)

m2 = mx(a,b)

print "%d" % min(m2,m1)