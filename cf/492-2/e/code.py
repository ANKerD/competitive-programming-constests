from sys import stdin, stdout

lim = 2250000000000
n = int(raw_input())
x = []
y = []
sx = sy = 0
sigma = 0;
for i in xrange(n):
    a, b = map(int, stdin.next().split())
    # sx += a
    # sy += b
    d = (sx+a)**2 + (sy+b)**2
    # print sx, sy, a, b
    if d > lim:
        nee = -1
        if i == 0:
            resp = "-1"
        else:
            resp = " -1"
    else:
        nee = 1
        if i == 0:
            resp = "1"
        else:
            resp = " 1"
    if n == 1:
        sx += a
        sy += b
        sigma = sx**2 + sy**2
    stdout.write(resp);
stdout.write("\n");
stdout.flush()
