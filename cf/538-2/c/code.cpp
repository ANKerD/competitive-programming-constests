#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 1000100
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

// bool p[maxn];
// void sieve(){
// 	memset(p, 1, sizeof p);
// 	for(int i = 2; i < maxn;){
// 		int j = i<<1;
// 		while(j<maxn){
// 			p[j]=0;
// 			j+=i;
// 		}
// 		i++;
// 		while(i < maxn && !p[i]) i++;
// 	}
// }
ll d[maxn];

int main(){
	ll a, b, bb;
	vll f;
	cin >> a >> b;
	if(b==2){
		trace(a/2 + (a+1)/4);
		return 0;
	}
	ll i = 2;
	for(; i < maxn; i++)
		if(!(b%i)){
			f.pb(i);
			d[i] = (a+i)/b;
		}
	ll ac = 0;
	for(auto j: f){
		if(j < b)
			ac += d[j];
		// break;
	}
	trace(a/b + ac);
	
 	return 0;
}
