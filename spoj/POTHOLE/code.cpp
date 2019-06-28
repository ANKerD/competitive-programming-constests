#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
const ll infl = ll(2e18) + ll(1e10);

namespace Dinic {
const int maxn = 100100;
struct Edge {
    int to;
    ll c, f;
    Edge(int to, ll c): to(to), c(c), f(0) {}
};

vector<Edge> es;
vector<int> g[maxn];
int q[maxn], d[maxn], pos[maxn];
int N, S, T;

void addEdge(int u, int v, ll c) {
    g[u].push_back(sz(es));
    es.emplace_back(v, c);
    g[v].push_back(sz(es));
    es.emplace_back(u, 0);
}

bool bfs() {
    fill(d, d + N, maxn);
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
    while (bfs()) {
        fill(pos, pos + N, 0);
        while (ll cur = dfs(S, infl))
            res += cur;
    }
    return res;
}

}

int main(){
	int t,k,node;
	cin >> t;
	while(t--) {
		cin >> Dinic::N;
		Dinic::es.clear();
		for (int i = 0; i <= Dinic::N; ++i)
			Dinic::g[i].clear();
		for (int i = 1; i < Dinic::N; ++i) {
			cin >> k;
<<<<<<< HEAD
			for (int j = 0; j < k; ++j) {
				cin >> node;
				if (i >= node) continue;
				
=======
			set<int> ns;
			for (int j = 0; j < k; ++j) {
				cin >> node;
				ns.insert(node);
			}
			for (auto node: ns) {
				// if (i >= node) continue;
>>>>>>> d95367a9dc4d15c7a2620527b10c655c8f9f4a48
				Dinic::addEdge(i-1, node-1, i == 1 || node == Dinic::N ? 1: 300);
			}
		}
		cout << Dinic::dinic(0, Dinic::N-1) << '\n';
	}
 	return 0;
<<<<<<< HEAD
}

=======
}
>>>>>>> d95367a9dc4d15c7a2620527b10c655c8f9f4a48
