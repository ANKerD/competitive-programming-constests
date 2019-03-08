#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 2000000
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
int main(){
	int n;
	cin >> n;
	int a[100];
	range(2*n){
		cin >> a[i];
	}

	sort(a,a+(2*n));

	int ans = INF;
	for(int i = 0; i < 2*n; i++)
		for(int j = i+1; j < 2*n; j++){
			vi p;
			for(int k = 0; k < 2*n; k++){
				if(k == i || k == j) continue;
				p.pb(a[k]);
			}
			int w = 0;
			// trace(n-1, (int) p.size());
			for(int k = 0; k < 2*(n-1); k+=2)
				w += p[k+1]-p[k];
			ans = min(ans,w);
		}
	trace(ans);

 	return 0;
}
