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
#define maxn 1010
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

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

map<ii, bool> clue;
vii pt;

ii sum(ii a, ii b){
	return mp(a.first+b.first,a.second+b.second);
}

ii sub(ii a, ii b){
	return mp(a.first-b.first,a.second-b.second);
}

int main(){
	ii lcl;
	int n, x, y;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		pt.pb(mp(x,y));
	}

	for(int i = 0; i < n; i++){
		cin >> x >> y;
		clue[mp(x,y)] = 1;
		lcl = mp(x,y);
	}

	ii pos;
	for(int i = 0; i < n; i++){
		pos = sum(pt[i], lcl);
		bool ok = true;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			ok = ok && clue[sub(pos, pt[j])];
			if(!ok) break;
		}
		if(ok){
			trace2(pos.first, pos.second);
			return 0;
		}
	}
	return 0;
}
