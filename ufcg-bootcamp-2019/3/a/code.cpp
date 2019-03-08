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

vll fact(ll n){
	vll ans;
	for(ll i = 1; i <= sqrt(n+1)+1; i++){
		if(!(n%i)) ans.pb(i);
	}
	return ans;
}

vi f[maxn];
bool p[maxn];

void sieve(){
	memset(p, 1, sizeof p);
	range(maxn){
		f[i].pb(1);
	}
	register int i = 2;
	while(i < maxn){
		register int j = i<<1;
		while(j < maxn){
			f[j].pb(i);
			p[j]=0;
			j+=i;
		}
		i++;
		while(i < maxn && !p[i]) i++;
	}
	range(maxn){
		if(i > 1)
			f[i].pb(i);
	}
}

int main(){
	
	sieve();
	
	ll n, m;
	cin >> n >> m;

	vi ft = fact(n);
	
	set<ll> fa;
	
	for(auto i: ft)
		for(auto j : f[i])
			fa.insert(j);
	
	vll a;
	for(auto it = fa.begin(); it != fa.end(); it++)
		a.pb(*it);
	a.pb(n);
	
	int t = 1;
	// int bound = min()
	while((int) a.size() < mid && t++ < m){
		vi c;
		for(int i = 0; i < (int) a.size(); i++){
			if(a[i] == n){
				for(auto it = fa.begin(); it != fa.end(); it++)
					c.pb(*it);
				c.pb(n);
			} else {
				for(auto it = f[a[i]].begin(); it != f[a[i]].end(); it++)
					c.pb(*it);
				if(a[i] > 2)
					c.pb(a[i]);
			}
		}
		a = c;
	}
	
	for(int i = 0; i < min(mid, (int) a.size()); i++)
		cout << a[i] << " \n"[i+1==min(mid, (int) a.size())];

 	return 0;
}
