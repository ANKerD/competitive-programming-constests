#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define maxn 100010
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
ll a[maxn],b[maxn],n,m;

ll get(ll x){
	ll ans = 0;
	for(int i = 0; i < n;i++)
		if(a[i] < x)
			ans += x-a[i];
	for(int i = 0; i < m;i++)
		if(b[i] > x)
			ans += b[i]-x;
	return ans;
}

int main(){
	ll m1,m2,g1,g2,l=0;
	ll r=1000000000;
	cin >> n >> m;
	for(int i = 0; i < n;i++) cin >> a[i];
	for(int i = 0; i < m;i++) cin >> b[i];
	sort(a,a+n);
	sort(b,b+m, greater<ll>() );
	ll ans = 1e15;
	while(l <= r){
		m1 = (2*l+r)/3;
		m2 = (2*r+l)/3;

		g1 = get(m1);
		g2 = get(m2);

		ans = min({ans,g1,g2});
		if(g1 < g2)
			r = m2-1;
		else
			l = m1+1;
	}
	trace(ans);
	return 0;
}
