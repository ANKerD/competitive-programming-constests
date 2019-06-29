#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

vector<pair<int, int> > g[maxn];
int dp[maxn][10*maxn];
pair<int, int> go[maxn][10*maxn];

int a, b;
int solve(int i, int left) {
	if (left == 0 && i == b) return 1;
	if (left <= 0) return 0;
	if (dp[i][left] != -1) return dp[i][left];
	dp[i][left] = 0;
	for (auto h: g[i]) {
		int u = h.first, cost = h.second;
		if (solve(u, left-cost)) {
			dp[i][left] = 1;
			go[i][left] = h;
			break;
		}
	}
	return dp[i][left];
}

int main(){
	int n,m,k,x,y,z;
	cin >> n >> m >> k >> a >> b;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	memset(dp, -1, sizeof dp);
	if (solve(a, k)) {
		vector<int> ans;
		while (k) {
			ans.push_back(a);
			int aux = go[a][k].first;
			k -= go[a][k].second;
			a = aux;
		}
		ans.push_back(b);
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << " \n"[i+1==ans.size()];
	} else cout << "Impossible\n";
 	return 0;
}

