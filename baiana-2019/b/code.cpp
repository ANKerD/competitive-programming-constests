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
#define INF 1e13
#define int long long

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll dp[1010][10010];

map<string, vector<ii> > comp;
map<int, string> back;

ll n, m;

ll solve(int i, int verba) {

	if (verba == 0 || i == n) return 0;
	if (verba < 0) return -INF;
	if (dp[i][verba]+1) return dp[i][verba];
	ll ans = max(0LL,solve(i+1, verba));
	for (auto u: comp[back[i]])
		if (verba-u.se >= 0)
			ans = max(ans, u.fi+solve(i+1, verba-u.se));
	return dp[i][verba] = ans;
}

int32_t main(){
	memset(dp, -1, sizeof dp);
	int verb;
	cin >> m >> verb;
	string city;
	int rating, cost;
	for (int i = 0; i < m; ++i) {
		cin >> cost >> rating >> city;
		comp[city].push_back(mp(rating, cost));
	}

	n = comp.size();
	int id = 0;
	for (auto u: comp)
		back[id++] = u.fi;

	cout << max(0LL,solve(0, verb)) << '\n';
 	return 0;
}

