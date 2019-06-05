


while True:
    n = int(raw_input())
    if n == 0: break
    t = int(raw_input())
    m=[]
    for i in range(n):
        x,y = map(int, raw_input().split())
        m.append((x, y))
    m.sort()
    m.reverse()

    print m
    
    i = 0
    ac = 0
    ans = 0
    while i < n and ac < t:
        x, y = m[i]
        if ac+y <= t:
            ac += y
            ans += x
        i += 1
    print '%d min.' % ans