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
#define maxn 160

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int w[maxn];
vi g[maxn];
int dp[maxn];

int solve(int i) {
	if (g[i].size() == 0) return 0;
	if (dp[i] != -1) return dp[i];

	dp[i] = 0;
	for (auto u: g[i])
		dp[i] = max(dp[i], 1+solve(u));
	return dp[i];
}

int main(){
	int p=-1,l,s, testct = 1, taht=-1;
	while(1) {
		cin >> p >> l >> s;
		if (p+l+s == 0) break;
		if (taht != -1) cout << '\n';
		taht = 1;
		for (int i = 1; i <= p; ++i) {
			cin >> w[i];
			g[i].clear();
			dp[i] = -1;
		}
		int x, y;
		for (int i = 1; i <= l; ++i) {
			cin >> x >> y;
			if (w[x] > w[y])
				g[x].push_back(y);
		}

		printf("Teste %d\n%d\n", testct++, solve(s));
	}
 	return 0;
}

