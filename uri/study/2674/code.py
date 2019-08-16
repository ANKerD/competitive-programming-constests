mx = 10**5+90

p = [True for i in xrange(mx)]
prim = set()

i = 2
while i < mx:
    prim.add(i)
    j = 2*i
    while j < mx:
        p[j] = False
        j += i
    i += 1
    while i < mx and not p[i]:
        i += 1

def isuper(a):
    for i in str(a):
        if not int(i) in prim:
            return False
    return True

while True:
    try:
        a = int(raw_input())
        if a in prim:
            if isuper(a):
                print 'Super'
            else:
                print 'Primo'
        else:
            print 'Nada'
        
    except EOFError:
        break
    except Exception as e:
        print e