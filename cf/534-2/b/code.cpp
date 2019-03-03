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
#define maxn (int) 1e5+10
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

string a;
int n;

bool vis[maxn];

int main(){
	memset(vis, 0, sizeof vis);
	cin >> a;
	n = (int) a.size();
	int i, j=1;
	i = 0;
	int cnt = 0;
	while(i < n-1){
		j = i+1;
		while(i >= 0 && j < n && a[i] == a[j] && !vis[i] && !vis[j]){
			vis[i] = vis[j] = 1;
			i--;
			j++;
			cnt++;
		}
		i = j;
	}
	// trace1(cnt);
	if(cnt&1){
		trace1("Yes");
	} else {
		trace1("No");
	}

 	return 0;
}
