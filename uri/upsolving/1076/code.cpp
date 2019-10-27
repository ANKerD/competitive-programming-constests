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
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int dfs(int v, vi g[], bool vis[]){
	int sz = 2;
	vis[v] = 1;
	for(auto u: g[v])
		if(!vis[u])
			sz += dfs(u, g, vis);
	return sz;
}

int main(){
	int t,n,a,b;
	cin >> t;
	while(t--){
		cin >> n >> a >> b;
		// x = sqrt(a+1);
		vi g[a];
		bool vis[a];
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < b; i++){
			int j, k;
			cin >> j >> k;
			g[j].pb(k);
			g[k].pb(j);
		}
		cout << dfs(n, g, vis) -2 << '\n';
	}
 	return 0;
}


