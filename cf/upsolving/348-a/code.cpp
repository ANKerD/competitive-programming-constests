#include <bits/stdc++.h>
#define maxn 100010
#define int long long
using namespace std;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn];
int n;

int32_t main(){
	cin >> n;
	int m = n-1, s = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(a[i], mx);
		s += a[i];
	}
	
	trace(max((s+m-1)/m, mx));

 	return 0;
}

