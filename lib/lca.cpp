#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int L = 20;

int idx;
int st[N], en[N];
int depth[N], a[N];
int parent[N][L];
vector<int> graph[N];

void dfs(int u) {
	a[idx] = u;
	st[u] = idx++;
	for (int v : graph[u]) 
		if (v != parent[u][0]) {
			parent[v][0] = 0;
			depth[v] = 1 + depth[u];
			dfs(v);
		}
	
	a[idx] = u;
	en[u] = idx++;
}

void build(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			parent[i][j] = -1;
		}
		depth[i] = 0;
	}
	dfs(0);
	for (int j = 1; j < L; ++j)
		for (int i = 0; i < n; ++i) 
			if (parent[i][j - 1] != -1) 
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
}

int get_lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);

		for (int i = L-1; i >= 0; --i)
			if (depth[u] - (1 << i) >= depth[v])
				u = parent[u][i];
		if (u == v) return u;
		for (int i = L-1; i >= 0; --i)
			if (parent[u][i] != parent[v][i])
				u = parent[u][i],
				v = parent[v][i];
	return parent[u][0];
}


