#include <bits/stdc++.h>
#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1];

#define loop1(l,r) for(int i = l; i <=r; i++)

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
	int n, s;
	cin >> n >> s;
	ll arr[n], ans=0;

	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	if(arr[n/2] == s){
		trace1(0);
		return 0;
	} else if(arr[n/2] < s){
		for(int i = n/2; i < n; i++){
			if(arr[i] < s) ans += s-arr[i];
			else break;
		}
	} else {
		// trace1("Hey");
		for(int i = 0; i <= n/2; i++){
			// trace2(i, arr[i]);
			if(arr[i] > s) ans += arr[i]-s;
			// else break;
		}
	}
	// trace1(s);
	// printArr(arr, n);
	trace1(ans);
 	return 0;
}
