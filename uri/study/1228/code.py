while True:
    try:
        
        n = int(raw_input())
        a = map(int, raw_input().split())
        b = map(int, raw_input().split())
        go = {}
        for i in range(n):
            go[a[i]] = i
        for i in range(n):
            b[i] = go[b[i]]
        ans = 0
        for i in range(n):
            j = 1
            while j < n:
                if b[j-1] > b[j]:
                    b[j-1], b[j] = b[j], b[j-1]
                    ans += 1
                j+=1
        print ans
        

    except Exception as e:
        # print e
        break

