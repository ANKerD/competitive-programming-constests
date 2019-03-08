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
	int p=0,g=0,x;
	range(n){
		cin >> x;
		if(x>0) p++;
		if(x<0) g++;
	}

	if(2*p>=n){
		trace(1);
	} else if(2*g>=n){
		trace(-1);
	} else {
		trace(0);
	}

 	return 0;
}
