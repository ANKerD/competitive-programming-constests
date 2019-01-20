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
#define maxn 200020
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
ll a[maxn][3];
ll n,l,r;
ll m[3];

ll solve(int i, ll md) {
	if(i == n) {
		return md == 0;
	}

	if(a[i][md] != -1) return a[i][md];

	ll ans = 0;
	for(int j = 0; j < 3; j++){
		ans = (ans + m[j]*solve(i+1, (md+j)%3)) % mod;
	}

	return a[i][md] = ans;
}

int get(int a, int b, int res) {
	while (a%3 != res) a++;
	while ((b+9)%3 != res) b--;
	if (b < a) return 0;
	return (b-a)/3+1;
}

int main(){
	memset(a, -1, sizeof a);
	cin >> n >> l >> r;
	
	m[0] = get(l, r, 0);
	m[1] = get(l, r, 1);
	m[2] = get(l, r, 2);

	
	trace1(solve(0, 0));
 	return 0;
}

