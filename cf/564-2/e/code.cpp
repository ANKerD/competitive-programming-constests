#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<ll, ll>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 200010
#define mod 998244353LL

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ii a[maxn];
ll ans[maxn];

ll expo(ll a, ll b) {
	if (!b) return 1;
	if (b&1) return a * expo(a,b-1) % mod;
	return expo(a * a % mod,b >> 1) % mod;
}

ll divide(ll a, ll b) {
	a = (a+mod)%mod;
	b = (b+mod)%mod;
	return a * expo(b, mod-2) % mod;
}

int main(){
	ll n,m, totalw = 0, increase = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].se;
		increase += a[i].se;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i].fi;
		totalw += a[i].fi;
	}
	
	ll chance = divide(m,n);
	// ll endweight = (totalw + divide(increase, n) - divide(n-increase, n)) % mod;
	ll endweight = (totalw + m*(2*increase-n)) % mod;
	
	trace("pora", totalw, endweight, chance);

	for (int i = 0; i < n; ++i) {
		ll w = a[i].fi;
		if(a[i].se) 
			w = divide(w+divide(w+chance, endweight), endweight);
		else
			w = w = divide(w-divide(w-chance, endweight), endweight);
		ans[i] = w;
	}

	for (int i = 0; i < n; ++i)
		trace(ans[i]);

 	return 0;
}

