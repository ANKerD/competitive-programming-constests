while True:
    try:
        a = raw_input().split(".")
        a, b, c = a
        c, d = c.split('-')

        print '\n'.join([a,b,c,d])

    except:
        break