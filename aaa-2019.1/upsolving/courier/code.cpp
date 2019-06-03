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
#define maxn 101
#define maxq 12
#define INF 1000000000

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int get(int i, int mask){return (1<<i) & mask;}
int zet(int i, int mask){return (1<<i) | mask;}

int n,m,b,k,qtd;
int d[maxn][maxn];
int dp[maxq][1 << maxq];
vector<ii> del;

int solve(int v, int mask){
	int start_node = del[v].se;
	
	if(mask == (1<<qtd)-1) return d[start_node][b];
	if(dp[v][mask] != -1) return dp[v][mask];
	dp[v][mask] = INF;
	for(int i = 0; i < qtd; i++){
		if(get(i, mask)) continue;
		int src = del[i].fi;
		int dest = del[i].se;
		dp[v][mask] = min(dp[v][mask], d[start_node][src] + d[src][dest] + 
			solve(i, zet(i, mask)));
	}
	return dp[v][mask];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> b;
		int x,y,z;
		
		for(int i = 0; i < maxn; i++)
			for(int j = 0; j < maxn; j++)
				if(i==j)
					d[i][j] = 0;
				else
					d[i][j] = INF;
		for(int i = 0; i < m; i++){
			cin >> x >> y >> z;
			d[x][y] = d[y][x] = z;
		}

		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
		del.clear();
		cin >> k;
		
		for(int g = 1; g <= k; g++){
			cin >> x >> y >> z;
			qtd += z;
			for(int j = 1; j <= z; j++)
				del.pb(mp(x,y));
		}
		qtd = del.size();
		int ans = INF;
		
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < qtd; i++){
			int bg = del[i].fi;
			int nd = del[i].se;
			
			ans = min(ans, d[b][bg] + d[bg][nd] + solve(i,zet(i, 0)));
		}
		cout << ans << '\n';
	}
 	return 0;
}
