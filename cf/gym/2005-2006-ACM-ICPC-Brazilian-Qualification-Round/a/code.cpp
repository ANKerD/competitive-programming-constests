#include <bits/stdc++.h>
#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1]);

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

int n,m;
bool special(){
	n = ((n % 100)-1+100)%100;
	m = ((m % 100)-1+100)%100;
	// trace2(n,m);
	return m/4==n/4;
}

int main(){
	double v;
	while(1){
		cin >> v >> n >> m;
		if(v==0&&n==0&&m==0)break;
		ld nn=0;

		cout << fixed << setprecision(2);
		if(n % 10000 == m % 10000) nn = 3000;
		else if(n % 1000 == m % 1000) nn = 500;
		else if(n % 100 == m % 100) nn = 50;
		else if(special()) nn = 16;
		cout << nn*v << '\n';
	}

 	return 0;
}
