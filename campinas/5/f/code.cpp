#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define maxn 1000010
#define mod 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

template<typename T>
void trace(T a){
	cout << a << "\n";
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << " ";
	trace(args...);
}

vi g[maxn];
int f[maxn];
int n;

int dfs(int v, int p){
	int sz = 1;
	for(auto u: g[v])
		if(u != p)
			sz += dfs(u,v);
	f[sz]++;
	return sz;
}

int main(){
	cin >> n;
	int x,y;
	for(int i = 0; i < n-1; i++){
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,1);
	vi ans;
	for(int i = 1; i < n; i++){
		if(n%(i+1)) continue;
		int dvd = n/(i+1);
		int ac = 0;
		for(int j = 0; j <= n; j+=dvd)
			ac += f[j];
		if(ac >= i+1)
			ans.pb(i);
	}
	for(int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << " \n"[i+1==(int)ans.size()];
	
	return 0;
}
