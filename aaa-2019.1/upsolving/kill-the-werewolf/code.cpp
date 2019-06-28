#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

//BEGIN_CODE
namespace PushRelabel {
const int maxn = 120;

struct Edge {
    int to, c, f;
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
    // printf("%d -> %d votes: %d\n", u,v,c);
    g[u].push_back(sz(edge));
    edge.push_back({v, c, 0});
    g[v].push_back(sz(edge));
    edge.push_back({u, 0, 0});
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
	int source = 0, sink = 119;
	int n,m,x,y,z;
    PushRelabel::n = 120;
	while (scanf("%d", &n) != EOF) {
        vector<int> g[n+1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &x, &y);
            g[i].push_back(x);
            g[i].push_back(y);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            forn (i, PushRelabel::n) PushRelabel::g[i].clear();
            PushRelabel::edge.clear();
            int votes = 0;
            for (int j = 1; j <= n; ++j) 
                if (count(all(g[j]), i))
                    ++votes;
            if (votes < 2 || 2*votes > n) {
                if (2*votes > n) ++ans;
                continue;
            }
            for (int j = 1; j <= n; ++j) {
                if (i == j || count(all(g[j]), i)) continue;
                PushRelabel::addEdge(source, j, 1);
                PushRelabel::addEdge(j, g[j][0]+n, 1);
                PushRelabel::addEdge(j, g[j][1]+n, 1);
                // printf("%d -> %d votes: %d\n", j,sink,votes - count(all(g[i]), j)? 2:1);
                if (count(all(g[i]), j)) 
                    PushRelabel::addEdge(j+n, sink, votes-1);
                else
                    PushRelabel::addEdge(j+n, sink, votes-1);
            }
            if (PushRelabel::flow(source, sink)+votes < n)
                ++ans;
        }
        printf("--- %d\n", ans);
        // break;
    }
	
	return 0;
}