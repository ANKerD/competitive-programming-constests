d = {
    'tesoura': ['papel', 'lagarto'],
    'papel': ['pedra', 'spock'],
    'pedra': ['lagarto', 'tesoura'],
    'spock': ['pedra', 'tesoura'],
    'lagarto': ['papel', 'spock']
}
n = int(raw_input())
for i in xrange(n):
    a,b = raw_input().split()
    if a == b:
        print 'empate'
    elif b in d[a]:
        print 'rajesh'
    else:
        print 'sheldon'