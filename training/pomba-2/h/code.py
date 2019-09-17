INF = 10 ** 19
MAX = 37
MOD = 10 ** 15 + 37

power = [0] * MAX
def build():
  power[0] = 1
  for i in range(1, MAX): 
    power[i] = (power[i-1]*127)%MOD

dp = [[-1 for j in range(MAX)] for i in range(MAX) ]

def memset():
  for i in range(MAX):
    dp[i] = [-1] * MAX

pts = [''] * 3
def calc(c, i, n):
	return (ord(c)*power[n-i-1])

def solve(idx,  pt, n):
	if idx > n: return 0
	# if dp[idx][pt] != -1: return dp[idx][pt]

	ans = INF  
	for i in xrange(3):
		ans = min((calc(pts[pt][idx-1], idx, n) + solve(idx+1, i, n))%MOD , ans)
	
	# dp[idx][pt] = ans
	return ans

build()
memset()
n, m = map(int, raw_input().split())

for i in range(3): pts[i] = raw_input()

ans1 = INF
for i in range(3): ans1 = min(solve(1, i, n)%MOD, ans1)

memset()
for i in range(3): pts[i] = raw_input()

ans2 = INF
for i in range(3): ans2 = min(solve(1, i, m), ans2)

if ans1 == ans2: print "Tie"
elif ans1 > ans2: print "Owls"
else: print "Goats" 
