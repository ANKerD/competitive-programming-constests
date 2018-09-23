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
int gcd(int a,int b){
	if(a==0)return b;
	return gcd(b%a,a);
}
int main(){
	int f[3];
	while(scanf("%d %d %d", f, f+1, f+2)!=EOF){
		sort(f, f+3);
		if(f[2]*f[2] != f[1]*f[1]+f[0]*f[0])
			printf("tripla\n");
		else if(gcd(f[0], f[1])==1&&gcd(f[0], f[2])==1&&gcd(f[2], f[1])==1)
			printf("tripla pitagorica primitiva\n");
		else
			printf("tripla pitagorica\n");
	}

 	return 0;
}
