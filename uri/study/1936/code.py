f = 1
a = []
for i in xrange(1,10):
    a.append(f*i)
    f *= i
n = int(raw_input())
b = [1 if i in a else 10 ** 10 for i in xrange(n+1)]
for i in xrange(n+1):
    for j in a:
        if j <= i:
            b[i] = min(b[i], 1+b[i-j])
    
print b[n]