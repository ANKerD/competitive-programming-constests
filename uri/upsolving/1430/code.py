d = {
    'W': 64,
    'H': 32,
    'Q': 16,
    'E': 8,
    'S': 4,
    'T': 2,
    'X': 1,
}

while True:
    try:
        a = raw_input()
        if a == '*': 
            break
        a = a[1:-1].split('/')
        t = 0
        for i in a:
            x = 0
            for j in i:
                x += d[j]
            if x == 64:
                t +=1
        print t
        
    except Exception as e:
        print e
        break