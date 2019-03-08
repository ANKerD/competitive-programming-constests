#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define mod 998244353LL
#define mul(a,b) a*b%mod

int expo(int a, int b, ll m){
	if(!b) return 1;
	if(b&1) return a*expo(a,b-1,m)%m;
	return expo(a*a%m,b>>1, m);
}
int expo(int a, int b){
	return expo(a,b,mod);
}

ii fact(int x){
	for(int i = 4; i >= 2; i--){
		int a = pow(x, 1.0/i);
		for(int j = -10; j <= 10; j++){
			int xp = expo(max(a+j, 0LL), i);
			if(xp == x){
				// printf("%lld %lld\n", i, a+j);
				return {i, a+j};
			}
		}
	}
	return {-1, x};
}

int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a, a);
}

bool solve[510];

int32_t main(){
	int n,x;
	
	scanf("%lld", &n);
	
	map<int, int> f;
	int ans = 1;
	
	memset(solve, 0, sizeof solve);
	vi num;
	for(int i = 0; i < n; i++){
		scanf("%lld", &x);
		ii q = fact(x);
		// printf("%lld %lld %lld\n",x, q.first, q.second);
		if(q.first != -1){			
			f[q.second] += q.first;
			solve[i]=1;
		}
		
		num.push_back(x);
	}

	map<int, int> uniq;
	for(int i = 0; i < n; i++){
		if(solve[i]) continue;
		int j = 0;
		for(; j < n; j++){
			int gx = gcd(num[i], num[j]);
			// printf("%lld %lld %lld\n", num[i], gx, num[i]/gx);
			if(i != j && gx > 1 && gx != num[i]){
				f[gx]++;
				f[num[i]/gx]++;
				solve[i] = 1;

				// printf("%lld %lld", gx, num[i]/gx);
				
				if(!solve[j]){
					f[gx]++;
					f[num[j]/gx]++;
					solve[j] = 1;
				}
				break;
			}
		}
		if(j == n && !solve[i])
			uniq[num[i]]++;
		solve[i] = 1;
	}

	for(auto it = f.begin(); it != f.end(); it++){
		// printf("%lld %lld\n", it->first, it->second);
		ans = mul(ans, (it->second+1));
	}

	for(auto it = uniq.begin(); it != uniq.end(); it++){
		// printf("%lld %lld\n", it->first, it->second);
		ans = mul(ans, (1+it->second)*(1+it->second));
	}

	// printf("%lld", expo(4, 58))
	printf("%lld\n", ans);
	fflush(stdout);

 	return 0;
}
