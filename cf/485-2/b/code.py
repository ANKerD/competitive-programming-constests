from math import log, sqrt

def pow(ary, a, b):
    ary[0] = a
    i = 1
    while(i < len(ary)):
        ary[i] = ary[i-1] ** 2
        i+=1

def power(a, b):
    ret = 1
    while b > 0:
        if(b%2 == 1):
            ret*=a
        b/=2
        a*=a
    return ret

a, b = map(int, raw_input().split())

# aa = [1 for i in xrange(int(log(b,2))+1)]
# bb = [1 for i in xrange(int(log(a,2))+1)]
#
# pow(aa, a, b)
# pow(bb, b, a)
#
# a1 = b
# answer1 = 1
#
# issss = int(log(max(a, b), 2))
# ith=[1, 2]
# for i in xrange(2, issss+1):
#     ith.append(ith[i-1] * ith[i-1])
#
# while(a1 > 0):
#     i = int(log(a1, 2))
#     answer1 *= aa[i]
#     a1 -= ith[i]
#
# a2 = a
# answer2 = 1
# while(a2 > 0):
#     i = int(log(a2, 2))
#     answer2 *= bb[i]
#     a2 -= ith[i]
answer1 = b * log(a)
answer2 = a * log(b)
if answer1 > answer2:
    print '>'
elif answer1 < answer2:
    print '<'
else:
    print '='
