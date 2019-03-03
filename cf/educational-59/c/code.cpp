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

ll a[maxn];

int main(){
	int n,k;
	cin >> n >> k;
	string p;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> p;
	ll s = 0, row = 0, mi;
	priority_queue<ll, vll > q;
	for(int i = 0; i < n; i++){
		if(i > 0 && p[i] != p[i-1]){
			int sz = (int)q.size();
			for(int j = 0; j < min(k,sz); j++){
				s+=q.top();
				q.pop();
			}
			
			while(!q.empty()) q.pop();
		} 
		q.push(a[i]);
	}
	int sz = (int)q.size();
	for(int j = 0; j < min(k,sz); j++){
		s+=q.top();
		q.pop();
	}
	trace1(s);

 	return 0;
}
