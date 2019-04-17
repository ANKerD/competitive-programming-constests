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
#define maxn 35
#define maxk 55
#define INF 1e9

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int dp[maxn][maxn][maxk];

int solve(int x, int y, int k){
	if(k == x*y || k == 0) return 0;
	if(k > x*y) return INF;
	
	if(dp[x][y][k] != -1) return dp[x][y][k];
	
	int ans = INF;
	for(int i = 1; i < x; i++){
		if(i*y <= k)
			ans = min(ans, y*y + solve(x-i, y, k-i*y));
		ans = min(ans, y*y + solve(x-i, y, k));	
	}
	
	for(int i = 1; i < y; i++){
		if(i*x <= k)
			ans = min(ans, x*x + solve(x, y-i, k-i*x));
		ans = min(ans, x*x + solve(x, y-i, k));	
	}

	return dp[x][y][k] = ans;
}

int main(){
	int t,n,m,k;
	cin >> t;
	memset(dp, -1, sizeof dp);
	
	while(t--){
		cin >> n >> m >> k;
		cout << solve(n,m,k) << '\n';
	}
 	return 0;
}

