def compu(a,b):
    if a[0] != b[0]: return -1 if a[0] < b[0] else 1
    if a[1] != b[1]: return -1 if a[1] > b[1] else 1
    return -1 if a[2] < b[2] else 1
fis = True


while True:
    n = int(raw_input())
    if n == 0: break
    if not fis: print ''
    fis = False

    a = []
    for i in xrange(n):
        c = raw_input()
        b = raw_input().split()
        a.append((b[0], b[1], c))
    a.sort(cmp=compu)

    for i in a:
        print ' '.join(i)