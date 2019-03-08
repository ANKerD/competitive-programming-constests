#include <bits/stdc++.h>
using namespace std;
#define int long long
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 2000000
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000100
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

ll gcd(ll a, ll b){
	if(!a) return b;
	return gcd(b%a,a);
}

int32_t main(){
	int n;
	ll a[100];
	cin >> n;
	range(n){
		cin >> a[i];
	}

	int mx = 0, ma=0;
	for(int i = 0; i < n; i++){

		ma = max(ma, a[i]);
		for(int j = i+1; j < n; j++){
			mx = gcd(mx, gcd(a[i], a[j]));
		}
	}
	

	if((ma/mx-n)&1)
		trace("Alice");
	else
		trace("Bob");

 	return 0;
}
