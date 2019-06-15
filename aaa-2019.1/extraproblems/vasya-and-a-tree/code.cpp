#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define INF 1e9+10
#define maxn 300010

map<int, ll> st;

void update(int i, int v){
	while (i < INF) {
		st[i] += v;
		i += i&-i;
	}
}

ll query(int i) {
	ll ans = 0;
	while (i) {
		ans += st[i];
		i -= i&-i;
	}
	return ans;
}

vi g[maxn];
ll ans[maxn];
vii qr[maxn];

void dfs(int v, int p, int level=1) {
	for (auto u: qr[v]) {
		int d = u.fi;
		int v = u.se;
		update(level, v);
		update(level+d+1, -v);
	}

	ans[v] = query(level);

	for (auto u: g[v])
		if (u != p)
			dfs(u, v, level+1);

	for (auto u: qr[v]) {
		int d = u.fi;
		int v = u.se;
		update(level, -v);
		update(level+d+1, v);
	}
}

int main(){
	int n,x,y,z;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int q;
	cin >> q;

	for (int i = 1; i <= q; ++i) {
		scanf("%d %d %d", &x, &y, &z);
		qr[x].push_back(mp(y,z));
	}

	dfs(1,1);

	for (int i = 1; i <= n; ++i)
		printf("%lld%c", ans[i], " \n"[i==n]);

 	return 0;
}

