ep = 100.0

a, b, c = map(float, raw_input().split())

x = 100.0

x -= ep/a
x -= ep/b
x -= ep/c

# print 2 ** -30
# print x

if x > 2 ** -30:
    print 'YES'
else:
    print 'NO'