n = int(raw_input())
def gcd(a,b):
    if a == 0: return b
    return gcd(b%a,a)
for i in range(n):
    a = int(raw_input(),2)
    b = int(raw_input(),2)
    # c = a^b
    # print a,b
    if gcd(a,b) > 1:
        print 'Pair #%d: All you need is love!' % (i+1)
    else:
        print 'Pair #%d: Love is not all you need!' % (i+1)