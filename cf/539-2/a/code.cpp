#include <bits/stdc++.h>
using namespace std;
#define range(n) for(ll i = 0; i < n; i++)
#define prllArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 101
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

template<typename T>
void trace(T a){
	cout << a << '\n';
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << ' ';
	trace(args...);
}

ll dp[maxn][maxn];
ll n, v;

ll solve(ll i, ll j){
	if(i == n) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll ans = INF;
	for(ll x = 0; x+j <= v; x++)
		if(j+x)
			ans = min(ans, x*i + solve(i+1, j + x - 1));
	return dp[i][j] = ans;
}

int main(){
	cin >> n >> v;
	memset(dp, -1, sizeof dp);
	trace(solve(1, 0));

 	return 0;
}
