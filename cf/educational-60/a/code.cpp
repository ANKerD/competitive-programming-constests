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
int l[maxn];

int main(){
	int n,mx=0;
	cin >> n;
	range(n){
		cin >> a[i];
		l[i] = 1;
		if(i > 0 && a[i] == a[i-1])
			l[i] += l[i-1];
		if(a[i] > a[mx])
			mx = i;
		else if(a[i] == a[mx])
			if(l[i] > l[mx])
				mx = i;
	}

	trace(l[mx]);

 	return 0;
}

