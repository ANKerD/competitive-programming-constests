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

int solve(int pos, int left){
	if(!left || !pos || pos == m+1) return 0;
	if(left == 1) return a[pos+1]-a[pos-1];
	if(dp[pos][left] != -1) return dp[pos][left];
	
	int ans = 1e9;
	for(int i = 0; i < left; i++){
		// trace(pos, left);
		// trace("to", pos, i, pos+i, left-i);
		ans = min(ans, solve(pos, i)+solve(pos+i+1, left-i-1));
	}
	int d = a[pos+left]-a[pos-1];
	return dp[pos][left] = ans + d;
}

int main(){
	while(cin >> n >> m){
		a[0] = 0;
		a[m+1] = n;
		for(int i = 1; i <= m; i++)
			cin >> a[i];
		memset(dp, -1, sizeof dp);
		cout << solve(1, m) << '\n';
	}
 	return 0;
}

