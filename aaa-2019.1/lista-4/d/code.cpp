#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 5060
#define INF 1e17

ll a[maxn];
ll dp[maxn][maxn];

ll n,k,x;
ll solve(ll left, ll i){
	
	if (i<=0) return 0;
	if (left == 0) {
		if (i > k) return -INF;
		else return a[i];
	}

	if (dp[left][i] != -1) return dp[left][i];
	
	ll ans = -INF;
	for (ll j = i-1; j+k >= i && j>0; j--)
		ans = max(ans, solve(left-1, j));

	return dp[left][i] = ans+a[i];
}

int main(){
	scanf("%lld %lld %lld", &n, &k, &x);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", a+i);
	a[n+1] = 0;

	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= m+1; i++)
		for (int j = 0; i+j <= m+1; j++){
			if (i == 1){
				dp[j][j+i] = 0;
				continue;
			}

			int ans = 1e9;
			
			int bg,nd;
			if (i == 2)	
				bg = j+1, nd = i+j;
			else 
				bg = op[j][i+j-1], nd = op[j+1][i+j];
			
			for (int k = bg; k <= nd; k++){
				int v = dp[j][k]+dp[k][j+i];
				if (ans > v){
					ans = v;
					op[j][j+i] = k;
				}
			}
			dp[j][j+i] = ans + a[j+i];
		}
	printf("%lld\n", max(-1LL, solve(x, n+1)));
 	return 0;
}
