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
#define INF 1e9

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vii toys;
ll fun[maxn];

ll solve(int i) {
	if (i == 0) return 0;
	if (i < 0) return -INF;
	ll &ans = fun[i];
	if (ans != -1) return ans;
	ans = 0;
	for (auto u: toys)
		ans = max(ans, u.se+solve(i-u.fi));
	return ans;
}

int main(){
	int n,t,id=1;
	while (true) {
		cin >> n >> t;
		if (n+t == 0) break;
		toys.clear();
		memset(fun, -1, sizeof fun);
		int x,y;
		for (int i = 0; i < n; ++i) {

			cin >> x >> y;
			toys.pb({x,y});
		}
		printf("Instancia %d\n", id++);
		trace(solve(t));
		cout << '\n';
	}
 	return 0;
}

