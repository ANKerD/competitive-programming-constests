#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[500010];
int n;

int main(){
	cin >> n;
	ll sz = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sz += a[i];
	}

	if (sz % 3) {
		trace(0);
		return 0;
	}
	sz /= 3LL;
	ll acum = 0, one = 0, ans = 0;
	for (int i = 1; i < n; ++i) {
		acum += a[i];
		if (acum == sz*2) ans += one;
		if (acum == sz) one++;
	}
	trace(ans);

 	return 0;
}

