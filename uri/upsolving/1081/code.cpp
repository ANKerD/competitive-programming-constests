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
#define maxn 50

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vi g[maxn];
bool vis[maxn];

void dfs(int v, int p, int sz){
	if(vis[v]) return;
	
	vis[v] = 1;
	if(v != p){
		for(int i = 0; i < sz; i++) 
			cout << "  ";
		printf("%d-%d pathR(G,%d)\n", p,v,v);
	} else if(v == p) cout << '\n';
	for(auto u: g[v])
		if(!vis[u])
			dfs(u,v,sz+1);
		else if(u != p and u > v)
			printf("  %d-%d\n", v,u);
}

int main(){
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++){
		int n,m;
		cin >> n >> m;
		for(int i = 0; i <= n; i++)	
			g[i].clear();

		int x,y;
		for(int i = 1; i <= m; i++){
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}

		memset(vis, 0, sizeof vis);
		printf("Caso %d:\n", z);
		for(int i = 0; i < n; i++)
			sort(g[i].begin(), g[i].end());
		for(int i = 0; i < n; i++)
			dfs(i, i, 0);
		cout << '\n';
	}

 	return 0;
}

