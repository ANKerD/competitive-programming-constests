#include <bits/stdc++.h>
#define MAXN 500010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];

#define swap(a, b) auto temp = a; a = b; b = temp;
#define mp makepair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<ll> vll;
typedef vector<double> vd;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true){
		int n, x;
		cin >> n;
		if(!n) break;
		vi a;
		for(int i = 0; i < n; i++){
			cin >> x;
			a.pb(x);
		}
		ll ans = 0;
		for(int i = 0; i < n; i++){
			if(a[(i-1+n)%n] < a[i] && a[(i+1+n)%n] < a[i]) ans++;
			if(a[(i-1+n)%n] > a[i] && a[(i+1+n)%n] > a[i]) ans++;
		}
		trace1(ans);
	}
	

 	return 0;
}
