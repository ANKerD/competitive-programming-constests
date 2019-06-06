while True:
    try:
        a = raw_input().split(".")
        a, b, c = a
        c, d = c.split('-')

        x = a+b+c

        q = 0
        for i in xrange(9):
            q += (i+1)*int(x[i])
            # print 'q',q

        w = 0
        for i in xrange(8, -1, -1):
            w += (9-i)*int(x[i])
            # print 'w',w, 9-i

        a = str((q%11)%10)+str((w%11)%10)
        # print a,d
        if a != d:
            print 'CPF invalido'
        else:
            print 'CPF valido'
        # break
    except:
        break