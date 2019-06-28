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
#define maxn 200010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

// void inline update(int i, int v, map<int, int> &st) {
// 	if (!i) return
// 	while (i < maxn) {
// 		st[i] = max(st[i], v);
// 		i += i&-i;
// 	}
// }

// int query(int i, map<int, int> &st) {
// 	int ans = 0;
// 	while (i) {
// 		ans = max(ans, st[i]);
// 		i -= i&-i;
// 	}
// 	return ans;
// }

int modlis(vi &a) {
	sort(a.begin(), a.end(), greater<int>() );
	int ans = a[0];
	int cur = a[0];
	for (int i = 1; i < a.size(); ++i) {
		ans += max(0, min(cur-1, a[i]));
		cur = min(cur-1, a[i]);
	}
	return ans;
}

int main(){
	int q,n;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		map<int, int> f;
		int x;
		for (register int i = 0; i < n; ++i) {
			scanf("%d", &x);
			++f[x];
		}
		vi a;
		for (auto u: f)
			a.pb(u.se);
		cout << modlis(a) << '\n';
	}
 	return 0;
}

