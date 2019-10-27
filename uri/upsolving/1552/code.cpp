#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<ld, ld>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 600

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}
int p[maxn];
vii g;

int find(int x){
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) p[y] = x;
}

ld half_hypot(ld a, ld b){return sqrt(a*a + b*b); }

int main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		ld x,y;
		g.clear();
		cin >> n;
		
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			// trace(t, n, x, y);
			p[i] = i;
			g.pb({x,y});
		}

		ld ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				q.push({-half_hypot(g[i].first - g[j].first, 
					g[i].second - g[j].second), {i, j}});
			}
		}


		// while (!q.empty()) {
		// 	ld cost = -q.top().fi;
		// 	x = q.top().se.fi;
		// 	y = q.top().se.se;
		// 	q.pop();
		// 	if (find(x) != find(y)) {
		// 		// trace(cost);
		// 		// ans += sqrt(cost);
		// 		ans += cost;
		// 		join(x,y);
		// 	}
		// }
		cout << fixed << setprecision(2); trace(ans/100);
	}
 	return 0;
}

