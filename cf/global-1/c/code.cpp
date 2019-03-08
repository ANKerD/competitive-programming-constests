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

int cnt(int x){
	int i = 0;
	int ans = 0;
	while(x){
		if(!(x&1))
			ans += 1<<i;
		i++;
		x>>=1;
	}
	
	return (ans);
}

int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a, a);
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int x,y;
		cin >> x;
		int su = x+1;
		if(su==(su&-su)){
			int ans = 1;
			int i = 1;
			while(i < x){
				ans = max(ans, gcd(x^i,x&i));
				i = 2*i+1;
			}
			trace1(ans);
		} else {
			cout << (x^cnt(x)) << "\n";
		}
	}

 	return 0;
}

