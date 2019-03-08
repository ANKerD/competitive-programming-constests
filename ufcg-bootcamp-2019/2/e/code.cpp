#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 710
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
map<int, int>  p;

int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a,a);
}

int find(int a){
	if(p[a] == a) return a;
	return p[a] = find(p[a]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b)
		p[b] = a;
}

int main(){
	int n;
	cin >> n;

	range(n){
		cin >> a[i];
		p[a[i]] = a[i];
	}

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if(gcd(a[i], a[j]) > 1)
				join(a[i], a[j]);

	set<int> v;
	for(int i = 0; i < n; i++)
		v.insert(find(a[i]));
	
	if((int) v.size() == 1)
		trace("Yes");
	else 
		trace("No");

 	return 0;
}
