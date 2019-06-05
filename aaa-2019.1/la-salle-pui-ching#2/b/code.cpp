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
#define maxn 500010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vi g[maxn];
int maxlevel = -1, dt;

void dfs(int v, int p, int l){
	if(maxlevel < l){
		maxlevel = l;
		dt = v;
	}
	for(auto u: g[v])
		if(u != p)
			dfs(u,v,l+1);
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i+1 < n; i++){
		int x,y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}

	dfs(1,1,0);
	maxlevel = -1;
	dfs(dt,dt,0);
	cout << (maxlevel+1)/2 << '\n';

 	return 0;
}

