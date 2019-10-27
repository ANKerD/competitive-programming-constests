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
#define maxn 110

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ii a[maxn];
int dp[maxn][maxn];

int n;

int solve(int i, int d){
	if(i == n) return 0;
	if(dp[i][d] != -1) return dp[i][d];
	dp[i][d] = solve(i+1, d);
	if(d >= a[i].se)
		dp[i][d] = max(dp[i][d], a[i].fi+solve(i+1, d-a[i].se));
	return dp[i][d];
}

int main(){
	int k,r,t,x,y;
	cin >> t;
	while(t--){
		cin >> n;
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			a[i] = {x,y};
		}

		cin >> k >> r;

		// trace(n,k,r, solve(0, k));
		if(solve(0, k) >= r)
			cout << "Missao completada com sucesso\n";
		else
			cout << "Falha na missao\n";
	}

 	return 0;
}

