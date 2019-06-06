#include <bits/stdc++.h>
#define maxn 30070
#define maxj 500
using namespace std;

int dp[maxn][maxj];
int jew[maxn];
int n, d, offset;

int solve(int i, int j) {
	if (i >= maxn) return 0;
	if (dp[i][j+offset] != -1) return dp[i][j+offset];
	
	int ans = max(solve(i+j, j),solve(i+j+1, j+1));
	if (j > 1) 
		ans = max(ans, solve(i+j-1, j-1));
	return dp[i][j+offset] = ans + jew[i];
}

int main(){
	cin >> n >> d;
	int x;
	memset(jew, 0, sizeof jew);
	for (int i = 0; i < n; i++) {
		cin >> x;
		++jew[x];
	}

	memset(dp, -1, sizeof dp);
	offset = 250-d;
	cout << solve(d, d);

 	return 0;
}

