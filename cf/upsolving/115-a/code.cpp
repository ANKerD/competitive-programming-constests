#include <bits/stdc++.h>
#define maxn 2010
using namespace std;

vector<int> g[maxn];

int dfs(int v) {
	int sz = 1;
	for (auto u: g[v])
		sz = max(sz, 1+dfs(u));
	return sz;
}

int main(){
	int n,x;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (x == -1) continue;
		g[x].push_back(i);
	}
	
	int ans = 1;
	for (int i = 1; i <= n; ++i) 
		ans = max(ans, dfs(i));
	cout << ans << '\n';
 	return 0;
}

