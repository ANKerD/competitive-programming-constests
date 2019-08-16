while True:
    try:
        a = raw_input()
        end = True
        i = 0
        ans = aux = ''
        while i < len(a):
            if a[i] == ']':
                if end: ans += aux
                else: ans = aux+ans
                aux = ''
                end = True
            elif a[i] == '[':
                if end: ans += aux
                else: ans = aux+ans
                aux = ''
                end = False
            else:
                aux += a[i]
            i += 1
        if end: ans += aux
        else: ans = aux+ans
        aux = ''
        print aux+ans
    except EOFError:
        break
    except Exception as e:
        print e
