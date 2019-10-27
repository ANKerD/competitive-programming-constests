#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define inf 1e9
#define maxn 511

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vi parent[maxn];
vi child[maxn];
int age[maxn];
bitset<maxn> vis;

int main(){
	int n,m,k,x,y;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> age[i];
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		parent[y].push_back(x);
		child[x].push_back(y);
	}
	for (int i = 1; i <= k; ++i) {
		char op;
		cin >> op;
		if (op == 'P') {
			cin >> x;
			int ans = inf;
			vis.reset();
			queue<int> q;
			for (auto u: parent[x])
				q.push(u);
			while (!q.empty()) {
				int top = q.front();
				q.pop();
				if (vis[top]) continue;
				vis[top] = true;
				for (auto u: parent[top]) {
					ans = min(ans, age[u]);
					q.push(u);
				}
			}
			if (parent[x].size() == 0) cout << "*\n";
			else cout << ans << '\n';
		} else {
			cin >> x >> y;
			
			for (auto &u : child[x])
				for (auto &v : parent[u])
					if (v == x)
						v = -y;
			for (auto &u : child[y])
				for (auto &v : parent[u])
					if (v == y)
						v = -x;
			for (auto &u : child[x])
				for (auto &v : parent[u])
					v = abs(v);
			for (auto &u : child[y])
				for (auto &v : parent[u])
					v = abs(v);
			swap(child[x], child[y]);
			swap(parent[x], parent[y]);
		}
	}

 	return 0;
}

