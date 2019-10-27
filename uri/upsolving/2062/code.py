def dts(a):
    if len(a) == 3 and a[:2] == 'OB': return 'OBI'
    if len(a) == 3 and a[:2] == 'UR': return 'URI'
    return a
n = int(raw_input())
l = raw_input().split()
m = map(dts, l)
print ' '.join(m)