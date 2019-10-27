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
#define maxn 100010
#define int long long

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll ans[maxn];

ll pc(ll x) {
	// ll ans = 0;
	// while(x) ++ans, x -= x&-x;
	return __builtin_popcount(x);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n,q,x,y,z;
		cin >> n;
		for (ll i = 1; i <= n; ++i) {
			cin >> x;
			ans[i] = 0;
			for (ll j = 0; j < x; ++j) {
				cin >> y;
				ans[i] |= 1LL << (y-1LL);
			}
		}
		cin >> q;
		while (q--) {
			cin >> x >> y >> z;
			ll cnt;
			if (x == 1) cnt = ans[y] & ans[z];
			else cnt = ans[y] | ans[z];
			trace(pc(cnt));
		}
	}
 	return 0;
}

