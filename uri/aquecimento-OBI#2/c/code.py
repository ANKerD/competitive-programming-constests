from math import pow, sqrt
for x in xrange(int(raw_input())):
    m, k = map(int, raw_input().split())
    mapa = []
    for i in xrange(k):
        mapa.append(raw_input())
    # print mapa
    for i in xrange(len(mapa)):
        for j in xrange(len(mapa[i])):
            if mapa[i][j] == 'J':
                jx = i
                jy = j
            elif mapa[i][j] == 'F':
                fx = i
                fy = j
    d = sqrt((jx-fx)**2 + (jy-fy)**2)
    print '%d dBs' % int(m*1/ ((.99 ** int(d*10))))
