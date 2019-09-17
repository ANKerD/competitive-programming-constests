#include <bits/stdc++.h>
using namespace std;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

const int maxn = 400;
int g[maxn][maxn];
vector<pair<int, int> > ans[maxn * maxn];
int n,m,k, visk=0;

inline void work(int &x, int &y, int z) {
	// printf("%d %d %d\n",x,y,z);
	visk |= z == k;
	g[x][y] = z;
	ans[z].push_back({x, y});
	if (y == m) {
		if (x&1) x++;
		else y--;
	} else if (y == 1) {
		if (x&1) y++;
		else x++;
	} else {
		if (x&1) y++;
		else y--;
	}
}

int main(){
	cin >> n >> m >> k;
	int left = k;
	int x = 1, y = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			g[i][j] = k;
	while (left--) {
		work(x, y, k-left);
		work(x, y, k-left);
	}
	// if (!visk)
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (g[i][j] == k)
				work(x, y, k);
	ans[k].pop_back();
	ans[k].pop_back();
	for (int i = 1; i <= k; ++i) {
		printf("%d ", ans[i].size());
		for (int j = 0; j < ans[i].size(); ++j)
			printf("%d %d%c", ans[i][j].first, ans[i][j].second, " \n"[j+1 == ans[i].size()]);
	}
		

 	return 0;
}

