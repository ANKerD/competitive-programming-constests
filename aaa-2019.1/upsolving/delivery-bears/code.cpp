#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll, ll>
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

//BEGIN_CODE
namespace PushRelabel {
    const int maxn = 1800;

    struct Edge {
        ll to, c, f;
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

    void addEdge(int u, int v, ll c) {
        // printf("votes: %d\n", c);
        if (c < 1) return;
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

vector<pii> g[70];
ll n,m,x,y,z,k;
ll solve(ld v) {
    PushRelabel::edge.clear();
    forn (i, 70)
        PushRelabel::g[i].clear();
    // cout << "desgraça\n";
    for (int i = 1; i <= n; ++i) {
        // printf("%lf disgraca\n", v);
        for (auto u: g[i]) {
            ll cap = u.second/v;
            if (cap > 0) {
                // printf("add %d -> %d = %ld\n", i,u.first,cap);
                PushRelabel::addEdge(i, u.first, cap);
            }
        }
    }
    return PushRelabel::flow(1, n);
}   

int main(){
    PushRelabel::n = 120;
	scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        scanf("%lld %lld %lld", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
    }

    // printf("%d %d %d\n",n,m,k);

    ld l = 0, r = 1e12;
    int iter = 145;
    while (iter--) {
        ld mid = (l+r)/2.0L;
        ld fft = solve(mid); 
        // cout << iter << ' '  << mid << ' '  << fft << '\n';
        if (fft >= k) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(20) << l*k << '\n';
	
	return 0;
}