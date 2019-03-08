#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 100010
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
typedef pair<int, int> ii;
typedef vector<int> vi;
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

vi f[maxn];
bool p[maxn];

void sieve(){
	memset(p, 1, sizeof p);
	register int i = 2;
	register int j;
	
	while(i < maxn){
		f[i].pb(i);
		j = i<<1;
		while(j < maxn){
			p[j] = 0;
			f[j].pb(i);
			j += i;
		}
		i++;
		while(i<maxn && !p[i]) i++;
	}
}
int last[maxn];
int sz[maxn];

int main(){
	sieve();
	int n;
	cin >> n;
	int a;
	int ans = 1;
	memset(last, -1, sizeof last);
	memset(sz, 0, sizeof sz);
	range(n){
		cin >> a;
		sz[i] = 1;
		for(int j : f[a]){
			if(last[j] != -1){
				sz[i] = max(sz[i], 1+sz[last[j]]);
			}
			last[j] = i;
		}
		ans = max(ans, sz[i]);
	}
	trace(ans);
 	return 0;
}
