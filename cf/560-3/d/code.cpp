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
#define maxn 211111

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll f[maxn];
ll p[maxn];

int main(){
	ll n,t;
	cin >> t;

	int i = 2;
	while (i < maxn){
		f[i] = i;
		int j = i<<1;
		while (j < maxn)
			p[j] = 0;
			f[j] = min(f[j], i);
			j+=i
		i += 1
		while i < maxn and not p[1]:
			i+=1

	}
	while(t--){
		ll x;
		cin >> n;
		ll ans;
		cin >> ans;
		for(ll i = 1; i < n; i++){
			cin >> x;
			ans = ans * x/__gcd(x,ans);
		}
		cout << ans << '\n';
	}

 	return 0;
}

