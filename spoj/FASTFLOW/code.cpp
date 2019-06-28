#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
const int maxn = 100100;	
const ll infl = ll(2e18) + ll(1e10);

namespace Dinic {
	struct Edge {
		int to;
		ll c, f;
		Edge(int to, ll c): to(to), c(c), f(0) {}
	};

	vector<Edge> es;
	vector<int> g[maxn];
	int q[maxn], d[maxn], pos[maxn];
	int N,S,T;

	void addEdge(int u, int v, ll c) {
		g[u].push_back(sz(es));
		es.emplace_back(v,c);
		g[v].push_back(sz(es));
		es.emplace_back(u, 0);
	}

	bool bfs() {
		fill(d, d+N, maxn);
		d[S] = 0, q[0] = S;
		int rq = 1;
		forn (lq, rq) {
			int u = q[lq];
			for (int id: g[u]) {
				if (es[id].c == es[id].f)
					continue;
				int v = es[id].to;
				if (d[v] == maxn) {
					d[v] = d[u] + 1;
					q[rq++] = v;
				}
			}
		}
		return d[T] != maxn;
	}

	ll dfs(int u, ll curf) {
		if (u == T) 
			return curf;
		ll ret = 0;
		for (int &i = pos[u]; i < sz(g[u]); ++i) {
			int id = g[u][i];
			int v = es[id].to;
			ll delta = min(curf, es[id].c - es[id].f);
			if (delta == 0 || d[v] != d[u] + 1)
				continue;
			delta = dfs(v, delta);
			curf -= delta;
			ret += delta;
			es[id].f += delta;
			es[id ^ 1].f -= delta;
			if (curf == 0)
				return ret;
		}
		return ret;
	}

	ll dinic(int S, int T) {
		Dinic::S = S, Dinic::T = T;
		ll res = 0;
		while(bfs()) {
			fill(pos, pos+N, 0);
			while (ll cur = dfs(S, infl))
				res += cur;
		}
		return res;
	}
}

ll g[maxn][maxn];
int main(){
	memset(g, 0, sizeof g);
	int x,y,z,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p;
	
	cin >> n >> m >> p;
	Dinic::N = maxn;
	for (int i = 0; i < p; ++i) {
		cin >> x >> y;
		Dinic::addEdge(0, x, 1);
		Dinic::addEdge(x, y+maxn/2, 1);
		Dinic::addEdge(y+maxn, maxn-2, 1);
	}
	ll ans = Dinic::dinic(0, maxn-3);
	cout << ans << '\n';
	return 0;
}

