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

int main(){
	int n;
	cin >> n;
	// vi a;
	// if(n == 1){
	// 	trace1("1");
	// 	trace1("1");
	// 	return 0;
	// }

	trace1(n);
	for(int i = 0; i < n; i++){
		cout << 1 << " \n"[i==n-1];
	}

	// int i = 2;
	// while(n > 1){
	// 	if(n % i == 0){
	// 		a.pb(i);
	// 		n /= i;
	// 	} else i++;
	// }
	// trace1((int) a.size());
	// for(i = 0; i < (int) a.size(); i++){
	// 	cout << a[i] << " \n"[i==(int) a.size()-1];
	// }

 	return 0;
}
