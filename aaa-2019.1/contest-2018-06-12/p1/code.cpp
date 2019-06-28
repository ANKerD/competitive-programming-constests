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
#define maxn 5010
#define maxf 25

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll f,p,e,a,x,y;

ll dp[maxn][maxf];
ll cost[maxn][maxf];

int solve(int prog, int freq) {
	if (prog == p+1) return 0;
	if (dp[prog][freq] != -1) return dp[prog][freq];
	ll ans = cost[prog][freq] + solve(prog+1, freq);

	for (int i = 1; i <= f; ++i) {
		if (i == freq) continue;
		ans = min(ans, e*a + cost[prog][i] + solve(prog+1, i));
	}

	return dp[prog][freq] = ans;
}

int main(){
	while (1) {
		cin >> f >> p >> e >> a;
		if (f+p+e+a == 0) break;
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= p; ++i) 
			for (int j = 1; j <= f; ++j) {
				cin >> x >> y;
				cost[i][j] = x*y;
			}
		cout << solve(1,1) << '\n';
	}
 	return 0;
}

