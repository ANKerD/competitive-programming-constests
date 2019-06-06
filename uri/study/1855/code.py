from sys import setrecursionlimit

setrecursionlimit(10**5)

m = int(raw_input())
n = int(raw_input())

def ok(i=0, j=0, dx=0, dy=0):
    if i < 0 or j < 0 or j >= m or i >= n:
        return False

    if vis[i][j]:
        return False
    
    vis[i][j] = True
    
    if g[i][j] == '*':
        return True
    
    if g[i][j] != '.':
        dx = dy = 0
        if g[i][j] == '>':
            dx = 1
        if g[i][j] == '<':
            dx = -1
        if g[i][j] == '^':
            dy = -1
        if g[i][j] == 'v':
            dy = 1

    return ok(i+dy, j+dx, dx, dy)

g = []
vis = []
for i in xrange(n):
    g.append(raw_input())
    vis.append([False for i in xrange(m)])

# for i in g:
#     print i

if ok():
    print('*')
else:
    print('!')