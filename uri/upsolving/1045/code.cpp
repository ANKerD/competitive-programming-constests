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
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<ll> vll;
typedef vector<double> vd;

int cmp(ld a, ld b){
	if(fabs(a-b) < eps) return 0;
	return a < b? -1:1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	double a,b,c;
	cin >> a >> b >> c;
	vi x;
	x.pb(a);
	x.pb(b);
	x.pb(c);
	sort(x.rbegin(), x.rend());
	a = x[0];
	b = x[1];
	c = x[2];
	if(cmp(a , (b+c))==0){
		trace1("NAO FORMA TRIANGULO");
		return 0;
	} 
	if(cmp(a*a, b*b+c*c) == 0) trace1("TRIANGULO RETANGULO");
	if(cmp(a*a, b*b+c*c)  == 1) trace1("TRIANGULO OBTUSANGULO");
	if(cmp(a*a, b*b+c*c)  == -1) trace1("TRIANGULO ACUTANGULO");
	if(!cmp(a,b) && !cmp(b,c) && !cmp(a,c)) {
		trace1("TRIANGULO EQUILATERO");
	} else if(!cmp(a,b) || !cmp(b,c) || !cmp(a,c)) {
		trace1("TRIANGULO ISOSCELES");
	}

 	return 0;
}
