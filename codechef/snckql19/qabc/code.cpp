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

ll s[maxn];
ll p[maxn];

void inline sum(int i, ll v){
	s[i] += v;
	s[i+1] += 2*v;
	s[i+2] += 3*v;
}

int main(){
	int n, t;
	scanf(" %d", &t);
	while(t--){
		scanf(" %d", &n);
		range(n){ scanf(" %lld", &s[i]); }
		range(n){ scanf(" %lld", &p[i]); }
		if(n < 3){
			bool diff = 0;
			for(int i = 0; i < n; i++)
				if(s[i] != p[i])
					diff=1;

			if(diff){
				trace1("NIE");
			} else {
				trace1("TAK");			
			}	
		} else {
			bool cont = 0;
			range(n-2){
				if(s[i] > p[i]){
					trace1("NIE");
					cont = 1;
					break;
				}
				sum(i, p[i]-s[i]);
			}
			if (cont) continue;
			if(s[n-1] != p[n-1] || s[n-2] != p[n-2]){
				trace1("NIE");
			} else {
				trace1("TAK");			
			}
		}
	}
 	return 0;
}
