def get(a):
    if a < 10: return a
    b = 0
    for i in str(a):
        b += int(i)
    return get(b)

while True:
    a,b = map(int, raw_input().split())
    if a+b == 0: break
    a = get(a)
    b = get(b)
    if a == b:
        print 0
    else:
        print 2 if a < b else 1