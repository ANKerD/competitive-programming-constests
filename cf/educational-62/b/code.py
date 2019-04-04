t = int(raw_input())
for x in xrange(t):
    n = int(raw_input())
    a = raw_input()
    if len(set(list(a))) == 1:
        print 0
        continue
    ans = n
    i = n-1
    while i >= 0 and a[i] == '>': i-=1
    ans = min(ans, n-1-i)
    i = 0
    while i < n and a[i] == '<': i+=1
    ans = min(ans, i)
    print ans