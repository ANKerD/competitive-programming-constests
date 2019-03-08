#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define maxn 10010
#define mod 1000000007
#define tp(a,b,c) mp(mp(a,b),c)
#define sc(a) scanf("%lld", &a);
#define sc2(a,b) sc(a); sc(b);
#define sc3(a,b,c) sc2(a,b); sc(c);

                                                       
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

ii purus(ii &a, ii &b){
	return mp(a.fi+b.fi,a.se+b.se);
}

ii dist[maxn];
ll cost[maxn];
vector<iii> g[maxn];

void dijkstra(){
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	dist[1] = mp(0,0);
	pq.push(tp(0,0,1));
	while(!pq.empty()){
		ii d = pq.top().fi;
		ll v = pq.top().se;
		pq.pop();
		if(d > dist[v]) continue;
		for(auto uu : g[v]){
			ii du = uu.fi;
			ll u  = uu.se;
			if(dist[u] > mp(dist[v].fi+du.fi,du.se)){
				dist[u] = mp(dist[v].fi+du.fi,du.se);
				cost[u] = du.se;
				pq.push(mp(dist[u], u));
			}
		}
	};
}

int main(){
	const ii INF = mp(1e17,1e17);
	memset(cost, 0, sizeof cost);
	ll n,m,x,y;
	
	ll c,l;
	sc2(n,m);
	for(int i = 2; i <= n; i++) dist[i]=INF;
	
	for(int i = 0; i < m; i++){
		scanf("%lld %lld %lld %lld", &x, &y, &l, &c);
		g[x].pb(tp(l,c,y));
		g[y].pb(tp(l,c,x));
	}
	dijkstra();
	ll ans = 0;
	for(int i = 2; i<= n; i++)
		ans += cost[i];
	cout << ans << "\n";
	return 0;
}
