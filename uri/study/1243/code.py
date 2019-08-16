while True:
    try:
        a = raw_input().split()
        total = ac = 0
        for i in a:
            while len(i) > 0 and not i[0].isalpha():
                i = i[1:]
            if '.' in i:
                l = i[-1]
                i = i.replace('.','')
                if l == '.':
                    i += '.'
            total += 1
            ac += len(i)
        if total == 0:
            a = 0
        else:
            a = ac / total 
        if a < 4:
            print 250
        elif a >= 6:
            print 1000
        else:
            print 500
    except EOFError:
        break
    except Exception as e:
        print e