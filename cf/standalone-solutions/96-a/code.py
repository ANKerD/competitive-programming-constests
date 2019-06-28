def lucky(a):
    while a > 0:
        if a % 10 not in [4,7]:
            return False
        a /= 10
    return True
n = int(raw_input())
for i in xrange(1, n+1):
    if lucky(i):
        if n % i == 0:
            print 'YES'
            exit()
print 'NO'