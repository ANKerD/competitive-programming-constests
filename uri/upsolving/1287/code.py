while True:
    try:
        a = raw_input()
        if a == '':
            print 'error'
            continue
        ans = 0
        ok = False
        for i in a:
            if i in ', ':
                continue
            if i == 'l':
                i = '1'
            if i.lower() == 'o':
                i = '0'
            if i.isdigit():
                ok = True
                ans = ans * 10 + int(i)
            if i.isalpha() or ans > 2147483647:
                ok = False
                break
        if not ok:
            print 'error'
        else:
            print ans
                
        
    except EOFError:
        break
    except Exception as e:
        print e