while True:
    try:
        a,b = raw_input().split()
        a = 0
        for i in b:
            a += int(i)
        if a % 3 == 0:
            print '%d sim' % (a)
        else:
            print '%d nao' % (a)
    except:
        break