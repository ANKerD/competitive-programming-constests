#include <bits/stdc++.h>
using namespace std;
#define maxn 300010
#define fi first
#define vii vector<ll>
#define ii pair<ll, ll>
#define se second
#define mp make_pair
#define pb push_back
#define ll long long

bool cmp(ii a, ii b){
	return a.se > b.se;
}

ii a[maxn];

ll solve(){
	ll ans = 0;
	ll s = 0;
	ll l = 1e7;
	for(ll i = 0; i < k; i++){
		s += a[i].fi;
		l = min(l, a[i].se);
		ans = max(ans, s*l);
	}
	return ans;
}

int main(){

	ll n, k;
	cin >> n >> k;

	for(ll i = 0; i < n; i++)
		cin >> a[i].fi >> a[i].se;

	sort(a,a+n, cmp);
	ans = solve();
	reverse(a,a+n);
	ans = max(ans, solve());
	s = 0;
	l = 1e7;

	
	cout << ans << '\n';

	return 0;
}