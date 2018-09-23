#include <bits/stdc++.h>
#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1]);

// #define swap(a, b) auto temp = a; a = b; b = temp;
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
	int n;
	char c;
	cin >> n;
	vector<int> a;
	vector<int> b;
	ll ans=0;
	for(int i = 0; i < n; i++){
		cin >> c;
		a.pb(c-'0');
	}
	for(int i = 0; i < n; i++){
		cin >> c;
		b.pb(c-'0');
	}
	for(int i = 0; i < n-1; i++){
		if(a[i] == b[i]) continue;
		if(a[i] == b[i+1] && a[i+1] == b[i]) swap(a[i], a[i+1]);
		else a[i] = b[i];
		ans++;
	}
	trace1(ans+abs(b[n-1]-a[n-1]));
 	return 0;
}
