#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 100010
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
#define int long long
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
int b[2][maxn];
int32_t main(){
	memset(b, -1, sizeof b);
	int n;
	cin >> n;
	vi a;
	int x;
	range(2*n){
		cin >> x;
		if(b[0][x] == -1) b[0][x] = i;
		else b[1][x] = i;
	}

	int ans = b[0][1] + b[1][1];
	int last[2];
	last[0] = b[0][1];
	last[1] = b[1][1];
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= 1; j++){
			ans += abs(b[j][i]-last[j]);
			last[j] = b[j][i];
		}
	}
	trace(ans);

 	return 0;
}
