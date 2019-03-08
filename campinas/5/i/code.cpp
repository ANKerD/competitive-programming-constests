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
int a[maxn],b[maxn];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n;i++) cin >> a[i];
	for(int i = 0; i < m;i++) cin >> b[i];
	sort(a,a+n);
	sort(b,b+m, greater<int>() );
	int ans = 0;
	for(int i = 0; i < min(n,m); i++)
		ans+=b[i]-a[i];
	trace(ans);
	return 0;
}
