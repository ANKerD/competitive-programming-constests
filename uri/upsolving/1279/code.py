def leap(n):
    return n % 400 == 0 or n % 100 > 0 and n % 4 == 0

def huluculu(n):
    return n % 15 == 0

def bulukulu(n):
    return n % 55 == 0 and leap(n)
p = False
while True:
    try:
        n = int(raw_input())
        if p: print ''
        p = True
        if not any([leap(n), huluculu(n), bulukulu(n)]):
            print 'This is an ordinary year.'
            continue
        if leap(n):
            print 'This is leap year.'

        if huluculu(n):
            print 'This is huluculu festival year.'

        if bulukulu(n):
            print 'This is bulukulu festival year.'

    except:
        break