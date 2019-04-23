#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 12
#define INF 100000000

int unset(int i, int mask){return ~(1<<i) & mask;}
int zet(int i, int mask){return (1<<i) | mask;}
int get(int i, int mask){return ((1<<i) & mask);}

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n,m;
int dp[maxn][1<<maxn];
int g[maxn][maxn];

int solve(int x, int mask){
	if(!get(x,mask)) return INF;
	
	if(dp[x][mask] != INF) return dp[x][mask];
	
	for(int i = 0; i < n; i++){
		if(i == x && g[x][i] != INF) continue;
		
		dp[x][mask] = min(dp[x][mask], 
				solve(i, unset(x,mask)) + g[x][i]);
	}
	return dp[x][mask];
}

int main(){
	cin >> n >> m;
	int x,y,z;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			g[i][j] = INF;
	
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		x--, y--;
		g[x][y] = g[y][x] = min(g[y][x], z);
	}
	
	for(int j = 0; j < n; j++)
		for(int i = 0; i < (1 << n); i++)
			if((1<<j) == i) dp[j][i] = 0;
			else dp[j][i] = INF;
	
	// int mx = (1<<n)-1;
	// for(int i = 0; i < n; i++)
	// 	trace(i, get(i, mx), mx);

	int ans = INF;
	for(int i = 0; i < n; i++)
		ans = min(ans, solve(i, (1<<n)-1));
	cout << ans << '\n';
 	return 0;
}

