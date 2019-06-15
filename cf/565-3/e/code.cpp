#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<pair<int, ii> >
#define ld long double
#define vll vector<ll>
#define maxn 200010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vi g[maxn];
bool vis[maxn];
bool cover[maxn];

void dfs(int v, bool add) {
	vis[v] = true;
	for (auto u: g[v])
		if (!vis[u]) {
			if (add) cover[u] = 0;
			dfs(u, !add);
		}
}

// void inline next

int main(){
	srand(time(0));
	int t;
	cin >> t;
	while (t--) {
		int n,m,x,y;
		cin >> n >> m;
		
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			vis[i] = 0;
			cover[i] = 1;
		}
		viii e;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}


		vi ans;
		do {
			int offset = rand() % n;
			for (int i = 0; i < n; ++i) 
				cover[i] = 1;
			int j;
			ans.clear();
			for (int i = offset; i < n+offset; ++i) {
				j = i % n;

				if (cover[j]) {
					ans.pb(j);
					for (auto u: g[j])
						cover[u] = 0;
				}
			}

		} while(ans.size() > n/2);
		

		assert(ans.size() <= n/2);

		trace(ans.size());
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i]+1 << " \n"[i+1==ans.size()];
	}
 	return 0;
}

