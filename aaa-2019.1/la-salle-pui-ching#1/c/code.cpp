#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n,r,k;

vi factor(){
	vi a;
	for(int i = 1; i <= sqrt(k); i++)
		if(k % i == 0)
			a.pb(i), a.pb(k/i);
	return a;
}

bool check(vi &z){
	ll ans = z[0];
	for(int i = 1; i < z.size(); i++){
		ans = static_cast<ll>(ans / __gcd(ans, (ll) z[i])) * z[i];
		assert(ans > 0);
		assert(z[i] != z[i-1]);
		// trace(ans);
	}
	return ans == k;
}

int main(){
	cin >> n >> r >> k;
	vi x = factor();
	vi y, z;
	for(int i = 0; i < x.size(); i++)
		if(x[i] <= r)
			y.pb(x[i]);
	set<int> a = set<int>(y.begin(), y.end());
	int ttl = n;
	for(auto it = a.rbegin(); it != a.rend(); it++)
		z.pb(*it);
	// reverse(z.begin(), z.end());
	if(n > z.size() || !check(z))
		cout << "-1\n";
	else
		for(int i = 0; i < n; i++)
			cout << z[i] << " \n"[i+1==n];
	// sort(y.begin(), y.end());
	// reverse(y.begin(), y.end());
 	return 0;
}

