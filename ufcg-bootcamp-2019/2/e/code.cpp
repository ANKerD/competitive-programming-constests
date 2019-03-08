#include <bits/stdc++.h>
using namespace std;
#define maxn 710

int a[maxn];

int cop[maxn][maxn];
int dp[maxn][maxn][2];

int _gcd(int a, int b){
	if(!a) return b;
	return _gcd(b%a,a);
}

int n;
int solve(int l, int r, bool p){
	if(dp[l][r][p] > -1) return dp[l][r][p];
	if(r <= l){
		if(!p) return dp[l][r][p] = cop[l-1][l] > 1;
		else return dp[l][r][p] = cop[r][r+1] > 1;
	}
	int parent = p? r+1 : l-1;
	
	for(int i = l; i <= r; i++){
		if(cop[i][parent] && solve(l, i-1, 1) && solve(i+1, r, 0))
			return dp[l][r][p] = 1;
	}
	
	return dp[l][r][p] = 0;
}

int main(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	a[0] = a[n+1] = 0;
	for(int i = 0; i < n; i++) cin >> a[i+1];

	for(int i = 0; i < n+2; i++)
		for(int j = i; j < n+2; j++)
			cop[j][i] = cop[i][j] = _gcd(a[i], a[j]);

	cop[0][0] = 89987;

	if(solve(1,n,0) || solve(1,n,1))
		printf("YES\n");
	else
		printf("NO\n");
	
 	return 0;
}
