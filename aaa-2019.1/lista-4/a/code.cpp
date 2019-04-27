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
#define maxn 1010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n, m, a[maxn];
int dp[maxn][maxn];

int solve(int i, int j){
	if(i+1>=j) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	int ans = 1e8;
	for(int k = i+1; k < j; k++)
		ans = min(ans, solve(i, k) + solve(k, j));
	
	int d = a[j]-a[i];
	return dp[i][j] = ans+d;
}

int main(){
	while(cin >> n >> m){
		a[0] = 0;
		a[m+1] = n;
		for(int i = 1; i <= m; i++)
			cin >> a[i];
		memset(dp, -1, sizeof dp);
		cout << solve(0, m+1) << '\n';
	}
 	return 0;
}