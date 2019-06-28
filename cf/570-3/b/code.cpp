#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll lng lng
#define ii pair<int, int>
#define vi vector<int>
#define ld lng double
#define vii vector<ii>
#define vll vector<ll>
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int q,n,k,a[110];
// int get(int x) {
// 	int ans = 0;
// 	for (int i = 0; i < n; ++i)
// 		ans += abs(a[i]-x);
// 	return ans;
// }

int main(){
	cin >> q;
	while (q--) {
		cin >> n >> k;
		int mx = 0, mn = 1e9;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		if (mx - mn > 2*k) {
			cout << "-1\n";
			continue;
		}
		cout << mn+k << '\n';
	}

 	return 0;
}

