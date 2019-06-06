#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007L
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll f[maxn], a[maxn];

ll expo(ll a, ll b){
	if(!b) return 1;
	if (b&1) return a * expo(a,b-1) % mod;
	return expo(a*a%mod, b>>1);
}

bool special(ll a){
	while (a) {
		if (a % 10 != 4 && a % 10 != 7)
			return false;
		a /= 10;
	}
	return true;
}

int main(){
	f[0] = f[1] = 1;
	for (int i = 2; i < maxn; i++)
		f[i] = i * f[i-1] % mod;

	ll n,k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	

 	return 0;
}

