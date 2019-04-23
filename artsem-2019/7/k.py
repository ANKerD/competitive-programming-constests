import string
n,m = map(int, raw_input().split())

a = raw_input()
b = raw_input()

if '*' not in a:
    if a == b:
        print 'YES'
    else:
        print 'NO'
    exit()

if n-1 > m:
    print 'NO'
    exit()

a = a.split('*')

if len(a[-1]) > 0:

    if b[:len(a[0])] == a[0] and b[-len(a[-1]):] == a[-1]:
        print 'YES'
    else:
        print 'NO'
else:
    if b[:len(a[0])] == a[0]:
        print 'YES'
    else:
        print 'NO'