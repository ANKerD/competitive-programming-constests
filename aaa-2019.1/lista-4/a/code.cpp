#include <bits/stdc++.h>
using namespace std;
#define maxn 1010

int n, m, a[maxn];
int dp[maxn][maxn];
int op[maxn][maxn];

int solve(int i, int j){
	if(i+1==j) {
		op[i][j] = j;
		return dp[i][j] = 0;
	}
	if(dp[i][j] != -1) return dp[i][j];

	int ans = 1e8;
	for(int k = i+1; k < j; k++){
		int tmp = solve(i, k) + solve(k, j);
		if (ans > tmp)
			ans = tmp, op[i][j] = k;
	}
	
	return dp[i][j] = ans+a[j]-a[i];
}

int main(){
	while(cin >> n >> m){
		a[0] = 0;
		a[m+1] = n;
		for(int i = 1; i <= m; i++)
			cin >> a[i];

		// for(int j = 0; j <= m+1; j++)
		// 	for(int i = j-1; i+1; i--){
		// 		if(i+1 >= j){
		// 			dp[i][j] = 0;
		// 			op[i][j] = i;
		// 			continue;
		// 		}
		// 	}


		memset(dp, -1, sizeof dp);
		cout << solve(0, m+1) << '\n';
		for(int i = 0; i <= m+1; i++){
			for(int j = 0; j <= m+1; j++)
				printf("%d,%d  |  ", dp[i][j], op[i][j]);
			cout << '\n';
		}
	}
 	return 0;
}
