#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n, f[maxn], dp[maxn];

int solve(int pos) {
	// trace(pos);
	if (pos <= 0) return 0;
	if (dp[pos] != -1) return dp[pos];
	int ans = solve(pos-1);
	if (f[pos])
		ans = max(pos*f[pos]+solve(pos-2), ans);
	// dp[pos] = max(pos+solve(pos-2), solve(pos-1));
	// trace(pos, dp[pos]);
	return dp[pos] = ans;
}

int32_t main(){
	memset(f, 0, sizeof f);
	memset(dp, -1, sizeof dp);
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		++f[x];
	}

	cout << solve(maxn-2) << '\n';

 	return 0;
}

