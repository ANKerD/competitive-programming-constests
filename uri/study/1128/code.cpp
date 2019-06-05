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
#define maxn 2020

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vi g[maxn];
int vis[maxn];
int sz;

void dfs(int v){
	if(vis[v]) return;
	// trace(--sz);
	--sz;
	vis[v] = 1;
	for (auto u: g[v])
		dfs(u);
}

int main(){
	int n,m,x,y,z;
	while (cin >> n >> m){
		if (n+m == 0) break;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 0; i < m; i++){
			cin >> x >> y >> z;
			g[x].pb(y);
			if(z-1)
				g[y].pb(x);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			memset(vis, 0, sizeof vis);
			sz = n;
			dfs(i);
			ans += sz;
		}
		cout << !ans << '\n';
	}
 	return 0;
}

