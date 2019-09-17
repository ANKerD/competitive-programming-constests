#include <bits/stdc++.h>
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
#define MAX 37
#define MOD 1000000000000037
#define INF 1e18 + 7

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}
using namespace std;
typedef long long ll;

ll power[MAX];
void build(){
	power[0] = 1;
	for(int i = 1; i < MAX; i++) power[1] = (power[i-1]*127LL)%MOD;
}

ll dp[MAX][MAX], n;
string pts[3];
ll calc(char c, int i){
	return (((ll)c)*power[n-i-1])%MOD;
}

ll solve(int idx, int pt){
	if(idx > n) return 0LL;
	
	//if(dp[idx][pt] != -1) return dp[idx][pt];

	ll ans = INF;
	for(int i = 0; i < 3; i++){
		ans = min((calc(pts[pt][idx-1], idx) + solve(idx+1, i))%MOD , ans);
	}

	//return dp[idx][pt] = ans;
	return ans;
}
int main(){
	memset(dp, -1, sizeof dp);
	int m; cin >> n >> m;
	for(int i = 0; i < 3; i++) cin >> pts[i];
	ll ans1 = INF;
	for(int i = 0; i < 3; i++) ans1 = min(solve(1, i), ans1);
	// ---------------
	n = m;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < 3; i++) cin >> pts[i];
	ll ans2 = INF;
	for(int i = 0; i < 3; i++) ans2 = min(solve(1, i), ans2);

	if(ans1 == ans2) { cout << "Tie\n"; return 0; }

	if(ans1 > ans2) cout << "Owls\n";
	else cout << "Goats" << endl; 
 	return 0;
}

