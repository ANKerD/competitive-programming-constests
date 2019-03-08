#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 50010
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

int a[maxn];

int main(){
	int n,x,o=0, t=0, mt=101;
	
	cin >> n;
	range(n){
		cin >> a[i];
		t+=a[i];
		mt = min(a[i], mt);
	}
	
	int tt = t;
	for(int i = 2; i <= 100; i++){
		for(int j = 0; j < n; j++)
			if(!(a[j]%i))
				tt = min(tt, t - a[j]+a[j]/i-mt+mt*i);
	}

	trace(tt);

 	return 0;
}
