a,b = map(int, raw_input().split())

if b >= a:

    if b >= 0 and b <= 2:
        print 'nova'
    elif b >= 97 and b <= 100:
        print 'cheia'
    else:
        print 'crescente'
elif b >= 3 and b <= 96:
    print 'minguante'
elif b < 3:
    print 'nova'
else:
    print 'cheia'