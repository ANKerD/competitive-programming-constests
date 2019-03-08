#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 2010
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

template<typename T>
void trace(T a){
	cout << a << '\n';
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << ' ';
	trace(args...);
}

ld d[maxn][maxn];

int n,_t;
ld p;
ld fib(int i, int t){
	// if(d[i][t] > -90) return d[i][t];
	
	if(t == _t || i == n) return i;

	return (p)*fib(i+1, t+1)+(1-p)*fib(i, t+1);
	
	// return d[i][t];
}

int main(){
	cin >> n >> p >> _t;
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			d[i][j] = -100;
	cout << fixed << setprecision(16) << fib(0,0);
 	return 0;
}