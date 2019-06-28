#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
const ll infl = ll(2e18) + ll(1e10);

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

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
	int n,k,node,z,st,dt,m, cap[110];
    int x, y;
    while(scanf("%d", &n) != EOF) {
        int S = 0, T = n+5;
        Dinic::N = T+10;
        for (int i = 0; i <= 2*Dinic::N; ++i)
            Dinic::g[i].clear();
        Dinic::es.clear();

        for (int i = 1; i <= n; ++i)
            cin >> cap[i];
        
        int g[110][110];
        int cap[110];
        memset(g, 0, sizeof g);
        // trace(n);
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> z;
            g[x][y] += z;
        }
        for (int i = 0; i < 110; ++i) {
            Dinic::addEdge(i, i+n, cap[i]);
            for (int j = 0; j < 110; ++j)
                if (g[i][j]) 
                    Dinic::addEdge(i+n, j, g[i][j]);
        }
        cin >> st >> dt;
        for (int i = 0; i < st; ++i) {
            cin >> x;
            Dinic::addEdge(S, x, infl);
        }
        for (int i = 0; i < dt; ++i) {
            cin >> x;
            Dinic::addEdge(x+n, T, infl);
        }
        cout << Dinic::dinic(S,T) << '\n';
    }
 	return 0;
}