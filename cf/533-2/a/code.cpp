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
#define maxn 2000000
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

int f[101];
int main(){
	int n, x;
	cin >> n;
	memset(f, 0, sizeof f);
	for(int register i = 0; i < n; i++){
		cin >> x;
		f[x]++;
	}
	ll c = 999999999999L, ans = 0;
	for(int register i = 1; i <= 100; i++){
		int cur = 0;
		for(int register j = 1; j <= 100; j++){
			if(abs(i-j) < 2) continue;
			cur += (abs(i-j)-1)*f[j];
		}
		if(cur < c){
			c = cur;
			ans = i;
		}
	}

	trace2(ans, c);
 	return 0;
}
