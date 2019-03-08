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
#define maxn 1000100
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

int f[maxn];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		f[x]++;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++){
		ans += f[i]/3;
		f[i] -= f[i]/3;
	}

	for(int i = 1; i <= m-2; i++){
		int dc = min({f[i], f[i+1], f[i+2]});
		ans += dc;
		for(int j = 0; j < 3; j++)
			f[i+j]-=dc;
	}

	trace1(ans);

 	return 0;
}
