def get():
    a = raw_input()
    if not a[0].isdigit(): a = '0'+a
    if not '.' in a: a += '.' 
    if a[-1] == '.': a+='0'
    return a

while True:
    try:
        a = get()
        c = get()

        # print 'disgraca',a,c,a[-1].isdigit()
        x,y = a.split('.')
        _,b = c.split('.')
        while len(b) < len(y): b += '0'
        while len(y) < len(b): y += '0'
        ans = int(x)
        inc = -1
        for i in xrange(len(y)):
            if y[i] != b[i]:
                inc = y[i] > b[i]
                break
        if inc == -1:
            inc = len(y) < len(b)
        if inc: ans += 1
        print ans
    except EOFError:
        break
    except Exception as e:
        print 'err',y,b
        break