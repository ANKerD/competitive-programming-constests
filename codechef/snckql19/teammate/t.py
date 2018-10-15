from sys import stdout
print 1
n = 10 ** 5
print(n)
for i in xrange(n):
    stdout.write(str(i/4+1))
    stdout.write(" \n"[i +1== n])
    
stdout.flush()