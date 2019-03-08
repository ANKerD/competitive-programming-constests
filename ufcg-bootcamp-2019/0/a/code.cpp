#include <bits/stdc++.h>
using namespace std;
#define int long long
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
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

int a;

int32_t main(){
	int q;
	cin >> q;
	vi odd;
	int n = -INF, ev = 0;
	range(q){
		cin >> a;
		if(a>=0){
			if(a&1) odd.pb(a);
			else ev += a;
		} else if((-a)&1) n = max(n,a);
	}

	int s = 0;
	sort(odd.begin(), odd.end());
	range(((int) odd.size())){
		s += odd[i];
	}
	ll ans;
	if(((int) odd.size()) > 0 && ((int) odd.size()) % 2 == 0)
		s-=min(odd[0],-n);
	else if(!(s&1))
		s+=n;
	
	trace(s+ev);
	
 	return 0;
}
