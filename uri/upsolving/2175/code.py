a,b,c = map(float, raw_input().split())
if a == b or b == c or a == c:
    print 'Empate'
elif a == min(a,b,c):
    print 'Otavio'
elif b == min(a,b,c):
    print 'Bruno'
else:
    print 'Ian'

