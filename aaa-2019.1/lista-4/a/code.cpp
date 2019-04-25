#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int dp[maxn][maxn];
int a[maxn];

int solve(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(j == 0) return 0;
	if(j == 1) return a[i+1]-a[i];
	int ans = 1e9;
	for(int k = 0; k < j; k++)
		ans = min(ans, solve(i, j-k-1));
	return dp[i][j] = ans+a[i+j]-a[i-1];
}

int main(){
	int n,m;
	while(cin >> n >> m){
		a[0] = 0;
		a[m+1] = n;
		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= m; i++)
			cin >> a[i];

		cout << solve(1, m) << '\n';
	}

 	return 0;
}

