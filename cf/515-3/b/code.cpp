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
#define maxn 1000000
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
	int n, r, ans=0, x;
	cin >> n >> r;
	vector< set<int> > arr;
	range(n) arr.pb( set<int>());
	range(n){
		cin >> x;
		if(x){
			ans++;
			for(int j = max(0, i-r+1); j < min(n, i+r); j++){
				arr[j].insert(i);
				// trace1(j);
			}
			// trace1("-------");
		}
	}
	// range(n){
	// 	for(auto it = arr[i].begin(); it!=arr[i].end(); it++)
	// 		cout << *it << ' ';
	// 	trace1("");
	// }
	range(n){
		if(!((int)arr[i].size())){
			// trace2(i, ((int)arr[i].size()));
			trace1(-1);
			return 0;
		}
	}
	range(n){
		bool rem=1;
		for(int j = max(0, i-r+1); j < min(n, i+r); j++)
			if(((int)arr[j].size())<2 || !arr[j].count(i)){
				rem=0;
				break;
			}

		if(rem){
			ans--;
			for(int j = max(0, i-r+1); j < min(n, i+r); j++)
				arr[j].erase(i);
		}
	}
	trace1(ans);
 	return 0;
}
