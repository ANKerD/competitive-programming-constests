#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef long long ll;

int a[maxn];
int b[maxn];
int n,m;
ll get(ll v) {
	ll ans = 0;
	forn (i, n) ans += max(0LL, v-a[i]);
	forn (i, m) ans += max(0LL, b[i]-v);
	return ans;
}

int main(){
	cin >> n >> m;
	forn (i, n) cin >> a[i];
	forn (i, m) cin >> b[i];
	ll ans = 1e15;
	int l = 0, r = 1e9;
	while (l < r) {
		// cout << "oi\n";
		int mid = (l+r)>>1;
		ll x1 = get(mid);
		ll x2 = get(mid+1);
		ans = min({ans, x1, x2});
		if (x1 < x2) r = mid;
		else l = mid+1;
	}
	cout << ans << '\n';
 	return 0;
}

