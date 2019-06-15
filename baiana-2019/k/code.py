
tims = defaultdict(nt)
l = raw_input().split()
for i in l:
    tims[i] = nt()
n = int(raw_input())

for i in xrange(n):
    t1, g1, t2, g2 = raw_input().split()
    g1 = int(g1)
    g2 = int(g2)
    
    tims[t1]['gol'] += g1
    tims[t1]['nome'] = t1
    tims[t2]['gol'] += g2
    tims[t2]['nome'] = t2

    if g1 > g2:
        tims[t1]['pt'] += 3
        tims[t1]['vit'] += 1
    elif g1 < g2:
        tims[t2]['pt'] += 3
        tims[t2]['vit'] += 1
    else:
        tims[t1]['pt'] += 1
        tims[t2]['pt'] += 1

zet = tims.values()
zet.sort(cmp=cmp)
print zet[0]['nome']
print zet[1]['nome']