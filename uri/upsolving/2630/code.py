n = int(raw_input())
for i in xrange(n):
    op = raw_input()
    inp = map(int, raw_input().split())
    r,g,b = inp

    if op == 'max': ans = max(inp)
    if op == 'min': ans = min(inp)
    if op == 'mean': ans = sum(inp)/3
    if op == 'eye': ans = .3*r + .59*g + .11*b

    print 'Caso #%d: %d' % (i+1, ans)
