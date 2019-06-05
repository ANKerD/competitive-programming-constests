#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair<ld, ld>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 1020

ld t;

struct tp {
	int fi;
	ii se;
};

ld wt(tp that){
	return that.se.fi*t + that.se.se;
}

inline bool operator < (const tp& lhs, const tp& rhs) {
  return wt(lhs) > wt(rhs) ? 1 : 0;
}

vector<tp> g[maxn];
ld d[maxn];
int n,m;

tp trp(int a, ld b, ld c){
	tp that;
	that.fi = a;
	that.se.fi = b;
	that.se.se = c;
	return that;
}

ld dijkstra(){
	for(int i = 2; i <= n; i++)
		d[i] = 1e30;
	d[1] = 0;
	priority_queue<tp, vector<tp> > pq;
	pq.push(trp(1,0,0));
	while(!pq.empty()){
		tp top = pq.top();
		pq.pop();
		int v = top.fi;
		ld u = wt(top);
		ld dist = d[v];

		if(u > dist) continue;

		for(auto u: g[v]){
			int y = u.fi;
			ld dy = wt(u);
			if(d[y] > dist + dy){
				d[y] = dist + dy;
				pq.push(trp(y, 0, d[y]));
			}
		}
	}
	return d[n];
}

int main(){

	while(scanf("%d %d", &n, &m) != EOF){
		int x,y,a,b;
		for(int i = 0; i < n; i++)
			g[i+1].clear();
		for(int p = 0; p < m; p++){
			scanf("%d %d %d %d", &x, &y, &a, &b);
			g[x].pb(trp(y,a,b));
			g[y].pb(trp(x,a,b));
		}

		int tries = 200;
		ld l = 0, r = 24*60, ans = 0;
		while(tries--){
			ld t1 = (2*l+r)/3;
			ld t2 = (2*r+l)/3;

			t = t1;
			ld a1 = dijkstra();

			t = t2;
			ld a2 = dijkstra();

			if(a1 < a2) l = t1;
			else r = t2;

			ans = max({ans, a1, a2});
		}

		printf("%.5Lf\n", ans);
		// break;
	}

 	return 0;
}