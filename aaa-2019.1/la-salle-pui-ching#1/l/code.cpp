#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 100000

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn];
int b[maxn];
map<int, int> f;
map<int, int> mt;

int main(){
	int n;
	cin >> n;
	// memset(f,0, sizeof f);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		f[a[i]]++;
	}

	sort(b, b+n);
	int last = b[0];
	for(int i = 0; i < n; i++){
		if(b[i] != last)
			mt[b[i]] = i;
		last = b[i];
	}

	for(int i = 0; i < n; i++){
		ld x1 = mt[a[i]] / static_cast<ld>(n);
		ld x2 = f[a[i]] / static_cast<ld>(n);
		ld x3 = (n-mt[a[i]]-f[a[i]]) / static_cast<ld>(n);
		cout << setprecision(15) << fixed;
		trace(x3,x2,x1);
	}

 	return 0;
}

