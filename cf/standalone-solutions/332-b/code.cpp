#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll a[maxn];
ll b[maxn];

int n,k;

int main(){
	cin >> n >> k;
	b[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i] + b[i-1];
		a[i] = 0;
	}
	ll ans = 0, f=0, g=0, curg=0, curf=0;
	for (int i = n-k; i+1 >= k; --i) {
		if ()
	}
	for (int i = k; i+k <= n; ++i) {
		trace(i);
	}

	// printf("%lld %lld\n", curf, curg);
 	return 0;
}

