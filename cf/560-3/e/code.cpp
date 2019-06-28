#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define maxn 211101
#define mod 998244353LL

ll a[maxn];
ll b[maxn];

int main(){
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		a[i] = a[i] * (n-i) * (i+1);
	}
	
	for(ll i = 0; i < n; i++)
		cin >> b[i];

	sort(a,a+n);
	sort(b,b+n, greater<ll> ());

	ll ans = 0;

	for(ll i = 0; i < n; i++){
		a[i] %= mod;
		ans = (ans + a[i] * b[i]) % mod;
	}
	
	cout << ans <<'\n';

 	return 0;
}


