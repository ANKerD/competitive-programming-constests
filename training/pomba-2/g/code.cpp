#include <bits/stdc++.h>
using namespace std;
#define maxn 10010

int deg[maxn];
int g[maxn];
int sz[maxn];

int dfs(int v) {
	if (!v) return 0;
	if (sz[v] != -1) return sz[v];
	return sz[v] = 1+dfs(g[v]);
}

int main(){
	memset(sz, -1, sizeof sz);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) deg[i] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> g[i];
		deg[g[i]]++;
	}
	for (int i = 1; i <= n; ++i) dfs(i);

	priority_queue<pair<int, int> > q;
	for (int i = 1; i <= n; ++i)
		if (!deg[i])
			q.push({sz[i], i});

	int left = n;
	int days = 0;
	while (left) {
		days++;
		int cur = k;
		vector<int> v;
		while (cur-- && !q.empty()) {
			int node = q.top().second;
			left--;
			q.pop();
			if (g[node]) {
				deg[g[node]]--;
				if (deg[g[node]] == 0) {
					v.push_back(g[node]);
				}
			}	
		}
		for (auto u: v)
			q.push({sz[u], u});
	}

	cout << days << '\n';
 	return 0;
}

