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
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){
	int n;
	scanf("%d", &n);
	int i = 1, j = 1, sz = 0;;
	vii ans;
	for (int k = 0; k < n; ++k)
		if (k&1) {
			ans.pb(mp(i,j));
			sz = max({i, sz, j});
			i++;
		} else {
			ans.pb(mp(i,j));
			sz = max({i, sz, j});
			j++;
		}
	printf("%d\n", sz);
	for (int k = 0; k < n; ++k)
		printf("%d %d\n", ans[k].fi, ans[k].se);
 	return 0;
}

