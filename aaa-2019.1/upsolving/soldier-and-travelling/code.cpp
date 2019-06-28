#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

//BEGIN_CODE
namespace PushRelabel {
const int maxn = 1200;

struct Edge {
    int from, to, c, f;
};
vector<Edge> edge;

int n;
vector<int> g[maxn];
ll e[maxn];
int h[maxn];
int onH[maxn];
int S, T;
int ptr[maxn];
int relabelTimer;

void addEdge(int u, int v, int c) {
    g[u].push_back(sz(edge));
    edge.push_back({u, v, c, 0});
    g[v].push_back(sz(edge));
    edge.push_back({v, u, 0, 0});
}

void push(int id, int delta) {
    int u = edge[id ^ 1].to;
    int v = edge[id].to;
    edge[id].f += delta;
    edge[id ^ 1].f -= delta;
    e[u] -= delta;
    e[v] += delta;
}

void gap(int ch) {
    forn (u, n) {
        if (h[u] > ch)
            h[u] = max(h[u], n);
    }
}

int o[maxn];
void globalRelabeling() {
    int oc = 0;
    forn (i, n) {
        h[i] = n;
        onH[i] = 0;
    }
    onH[0] = 1;
    h[T] = 0;
    o[oc++] = T;
    forn (ii, oc) {
        int u = o[ii];
        for (int id: g[u]) {
            if (edge[id ^ 1].c == edge[id ^ 1].f)
                continue;
            int v = edge[id].to;
            if (h[v] != n)
                continue;
            h[v] = h[u] + 1;
            onH[h[v]]++;
            o[oc++] = v;
        }
    }
}

void relabel(int u) {
    int oldh = h[u];
    int newh = inf;
    for (int id: g[u]) {
        if (edge[id].c == edge[id].f)
            continue;
        newh = min(newh, h[edge[id].to] + 1);
    }
    h[u] = newh;
    onH[oldh]--;
    onH[newh]++;
    if (onH[oldh] == 0)
        gap(oldh);
    if (++relabelTimer == n)
        globalRelabeling(), relabelTimer = 0;
}

void discharge(int u) {
    while (e[u] > 0) {
        int &i = ptr[u];
        if (i == sz(g[u])) {
            i = 0;
            relabel(u);
            if (h[u] >= n)
                break;
            continue;
        } else {
            int id = g[u][i++];
            int v = edge[id].to;
            if (h[v] + 1 != h[u])
                continue;
            int delta = min(e[u], ll(edge[id].c - edge[id].f));
            push(id, delta);
        }
    }
}

ll flow(int _S, int _T) {
    S = _S, T = _T;
    forn (i, n)
        ptr[i] = 0, e[i] = 0;
    for (int id: g[S]) {
        int delta = edge[id].c;
        push(id, delta);
    }
    globalRelabeling();
    bool ok = false;
    while (!ok) {
        ok = true;
        forn (u, n) {
            if (h[u] < n && u != T && e[u] > 0)
                discharge(u), ok = false;
        }
    }
    return e[T];
}

} //PushRelabel

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int source = 0, sink = 1100;
	int n,m,x,y,z;
	cin >> n >> m;
	PushRelabel::n = 1000;
    int smx = 0, smy = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        PushRelabel::addEdge(source, i, x);
        PushRelabel::addEdge(i, i+n, x);
        smy += x;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        smx += x;
        PushRelabel::addEdge(i+n, sink, x);
    }

    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        PushRelabel::addEdge(x, y+n, inf);
        PushRelabel::addEdge(y, x+n, inf);
    }
	
    // printf("%d %lld\n", sm, PushRelabel::flow(source, sink));
    if (smx == smy && smx == PushRelabel::flow(source, sink)) {
        int mx[n+1][n+1];
        cout << "YES\n";
        memset(mx, 0, sizeof mx);
        for (auto u: PushRelabel::edge) {
            if (u.from != source && u.to != sink && u.c > 0) {
                mx[u.from][u.to-n] = u.f;
            }
        }
        for (int i = 1; i <=n ; ++i)
            for (int j = 1; j <= n; ++j)
                cout << mx[i][j] << " \n"[j==n];
    } else cout << "NO\n";
	
	return 0;
}