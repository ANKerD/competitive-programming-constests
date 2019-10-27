while True:
    try:
        n = int(input())
        m = n//2
        for i in range(m+1):
            print(' ' * (m-i) + '*'*(2*i+1))
        for i in range(2):
            print(' ' * (m-i) + '*'*(2*i+1))
        print()
    except Exception as e:
        # print (e)
        break