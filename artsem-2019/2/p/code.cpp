// given two number a, b such that 1 <= a <= b <= 4*10^12
// and b-a <= 2*10^6 calculate the sum of all euler's totient
// function φ(n) 
#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define ll long long
#define maxn 2000010

using namespace std;

ll p[maxn];
ll ar[maxn];
vll f[maxn];

ll a, b;

ll g2(ll i){
	ll x = i-a%i;
	if(x==i)x=0;
	return x;
}

int32_t main(){
	cin >> a >> b;
	for(ll i = 0; i <= b-a; i++) ar[i] = a+i;
	
	ll i = 2;
	for(ll i = 0; i < maxn; i++) p[i]=1;
	ll t = 0;
	while(i < maxn){
		ll j = i<<1;
		while(j < maxn){
			p[j]=0;
			j+=i;
		}
		
		j = g2(i);
		for(; j <= b-a; j+=i){
			while(!(ar[j] % i)){
				ar[j] /= i;
			}
			f[j].pb(i);
		}
		i++;
		while(i < maxn && !p[i]) i++;
	}

	ll ans = 0;
	for(i = 0; i <= b-a; i++){
		ll pa = 1, pu = 1;
		
		if(1 < ar[i]){
			pa *= ar[i]-1;
			pu *= ar[i];
		}

		for(ll j: f[i]){
			pa *= j-1;
			pu *= j;
		}
		ans += (a+i)/pa*pu;
	}
	
	cout << ans << '\n';

 	return 0;
}
