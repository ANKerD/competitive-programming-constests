def get(a,b):
    return 2 if a+b in 'rgbr' else 1


t = int(raw_input())
for _ in range(t):
    n = int(raw_input())
    g = {'g':0,'r':0,'b':0}
    for _ in range(n):
        a,b = raw_input().lower().split()
        g[a] += get(a,b)
    mx = max(g.values())
    if g['r'] == g['g'] == g['b']:
        print 'trempate'
    elif mx == g['r'] == g['g'] or mx == g['r'] == g['b'] or mx == g['b'] == g['g']:
        print 'empate'
    elif mx == g['r']:
        print 'red'
    elif mx == g['g']:
        print 'green'
    else:
        print 'blue'
