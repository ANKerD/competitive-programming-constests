#include <bits/stdc++.h>
using namespace std;
#define int long long
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 1001
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
ll a[maxn];
int32_t main(){
	ll n, m;
	cin >> n >> m;
	range(n){
		cin >> a[i];
	}
	
	sort(a,a+n);

	int i = 0, cnt = 0;
	while(i < n){
		while(2*m < a[i]){
			cnt++;
			m *= 2;
		}
		m = max(m,a[i++]);
		
	}
	trace(cnt);

 	return 0;
}
