#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<ll, ll>
#define vi vector<ll>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 211101
#define mod 998244353

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll a[maxn];
ll b[maxn];

int main(){
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		a[i] = a[i] * (n-i) % mod * (i+1) % mod;
	}
	for(ll i = 0; i < n; i++){
		cin >> b[i];
		// b[i]
	}
	sort(a,a+n);
	sort(b,b+n, greater<ll> ());

	// for(ll i = 0; i < n; i++)
	// 	trace(a[i], b[i]);

	ll ans = 0;

	for(ll i = 0; i < n; i++){
		// ans = ans + (a[i]*b[i] % mod *(i+1) * (n-i)) % mod ;
		// ans = (ans + a[i]*b[i] % mod * (n-i) % mod *(i+1)) % mod;
		ans = (ans + a[i] * b[i]) % mod;
		// trace((n-i) % mod *(i+1), ans);
	}
	
	cout << ans <<'\n';

 	return 0;
}

