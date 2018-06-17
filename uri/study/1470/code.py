def fold(ans, arr, i):
    ra = arr[-i:]
    ra.reverse()
    a = arr[:-i]
    for i in xrange(min(len(ra), len(a))):
        a[-i-1] += ra[-i-1]
    if len(ra) > len(a):
        a = ra[:(len(ra)-len(a))] + a

    resp =  ' '.join(map(str, a))
    if resp in ans:
        return
    ans.add(resp)
    for i in xrange(1,len(a)):
        fold(ans, a, i)

while True:
    try:
        n = int(raw_input())
        a = map(int, raw_input().split())
        m = int(raw_input())
        b = raw_input()
        ans = set()
        ans.add(' '.join(map(str, a)))

        for i in xrange(1,len(a)+1):
            fold(ans, a, i)
        answer = 'N'

        for i in ans:
            # print i
            if i == b:
                answer = 'S'
        print answer
    except EOFError:
        break
