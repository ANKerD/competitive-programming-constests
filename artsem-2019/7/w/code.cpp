// given two number a, b such that 1 <= a <= b <= 4*10^12
// and b-a <= 2*10^6 calculate the sum of all euler's totient
// function φ(n) 
#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define ll long long
#define maxn 1010

using namespace std;

ll p[maxn];
ll ar[maxn];
vll f[maxn];

int32_t main(){
	int n;
	cin >> n;
	int i=2;
	fill(p,p+maxn,1);
	vll ans;
	while(i < maxn){
		ll j = i<<1;
		while(j < maxn){
			p[j]=0;
			f[j].pb(i);
			j+=i;
		}

		j = i;
		while(j <= n){
			ans.pb(j);
			j*=i;
		}
		
		i++;
		while(i < maxn && !p[i]) i++;
	}

	cout << (int) ans.size() << '\n';
	for(i=0; i < (int) ans.size(); i++)
		cout << ans[i] << " \n"[i+1==(int) ans.size()];

 	return 0;
}
