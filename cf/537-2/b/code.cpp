#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 200010
#define mod 1000000007
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
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

ld h[maxn];

int main(){
	int n,k,m;
	ld md = 0;
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++){
		cin >> h[i];
		md += h[i]/n;
	}
	
	sort(h,h+n);
	ld ans=0;
	if(m >= n){
		// trace1("hero");
		ans = h[n-1]+min(m-n+1, k);
	} else {
		
		ld s = 0;
		for(int i = 0; i < n; i++)
			s+=h[i];
		
		ld ac=0;
		ld kk = k;
		for(int i = 0; i <= m; i++){
			// if(m<=i) break;
			ld inc = min(kk,( (ld) (m-i) ) / (n-i)  );
			ans = max(ans, (s-ac)/(n-i)+inc);
			ac += h[i];
		}
	}
	cout << fixed << setprecision(20) << ans << "\n";
	

 	return 0;
}

