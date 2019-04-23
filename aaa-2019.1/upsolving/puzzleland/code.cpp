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
#define maxn 16

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n,m,t,s[266];
char w[26];

vector<char> g[266];

int dp[maxn][1 << maxn];
ii sub[maxn][1 << maxn];

int get(int i, int mask){return (1<<i) & mask;}
int unzet(int i, int mask){return mask^(1<<i);}
int zet(int i, int mask){return mask|(1<<i);}

int solve(int i, int mask){
	if((1<<n)-1 == mask) return i == s[(int)w[n-1]];
	if(dp[i][mask] != -1) return dp[i][mask];
	dp[i][mask] = 0;
	for(auto u: g[(int)w[i]]){
		int v = s[(int)u];
		if(!get(v, mask)){
			if(solve(v, zet(v, mask))){
				sub[i][mask] = mp(v, zet(v, mask));
				dp[i][mask] = 1;
				break;
			}
		}
	}
	return dp[i][mask];
}

int main(){
	cin >> t;
	for(int alpha = 1; alpha <= t; alpha++){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> w[i];
			g[(int)w[i]].clear();
			s[(int)w[i]] = i;
		}

		
		char x,y;
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			g[(int)x].pb(y);
			g[(int)y].pb(x);
		}

		for(int i = 0; i < 266; i++)
			sort(g[i].begin(), g[i].end());

		printf("Case %d: ", alpha);
		
		memset(dp, -1, sizeof dp);
		int nd = 0;
		int mask = 1;

		int ttl = n;

		if(solve(nd, mask)){
			vector<char> ans;
			mask = 1;
			while(ttl--){
				
				ans.pb(w[nd]);
				int nnd = sub[nd][mask].fi;
				mask = sub[nd][mask].se;
				nd = nnd;
			}
			
			for(auto jhcghjg: ans)
				cout << jhcghjg;
			
		}
		else
			cout << "impossible";
		cout << '\n';
	}
 	return 0;
}

