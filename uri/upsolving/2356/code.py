while True:
    try:
        a = raw_input()
        b = raw_input()
        if b in a:
            print 'Resistente'
        else:
            print 'Nao resistente'
    except:
        break