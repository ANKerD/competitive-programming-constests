#include <bits/stdc++.h>
using namespace std;
#define range(n) for(ll i = 0; i < n; i++)
#define prllArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define mid 100000
#define maxn 1000010
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

template<typename T>
void trace(T a){
	cout << a << '\n';
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << ' ';
	trace(args...);
}

map<ll, set<ll> > prc;
set<ll> fact(ll n){
	if(prc.count(n)) return prc[n];
	// trace("hjhk");
	set<ll> ans;
	for(ll i = 1; i <= sqrt(n); i++){
		if(!(n%i)){
			ans.insert(i);
			ans.insert(n/i);
		}
	}
	return prc[n] = ans;
}

bool p[maxn];

int main(){
	
	ll n, m;
	cin >> n >> m;
	m = min(m,ll(mid));
	
	vll a;
	a.pb(n);
	
	int t = 0;
	
	while((int) a.size() < mid && t++ < m){
		// trace(t);
		vi c;
		for(int i = 0; i < (int) a.size(); i++){
			set<ll> xxt = fact(a[i]);
			for(auto j: xxt)
				c.pb(j);
		}
		a = c;
	}
	
	for(int i = 0; i < min(mid, (int) a.size()); i++)
		cout << a[i] << " \n"[i+1==min(mid, (int) a.size())];

 	return 0;
}
