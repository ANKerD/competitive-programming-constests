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
#define maxn 300010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n;
ii v[maxn];

vector<ii> ans;

bool gt(ii a, ii b){ return a.fi < b.fi;}

bool cmp(ii &a, ii &b) {
	// trace("ord", a.fi < b.fi, a.fi ,b.fi);
	if (2*abs(a.se - b.se) < n)
		return true;
	if (a.fi < b.fi)
		return true;
	ans.push_back(mp(a.fi, b.fi));
	swap(a.se, b.se);
	return false;
}

int main(){
	cin >> n;
	for (register int i = 0; i < n; ++i) {
		scanf("%d", &v[i].fi);
		v[i].se = i;
		// trace(v[i].fi, v[i].se);
	}

	while (!is_sorted(v,v+n, cmp)) {
		sort(v,v+n, cmp);
	}

	printf("%d\n", (int) ans.size());
	for (register int i = 0; i < (int) ans.size(); ++i) 
		printf("%d %d\n", min(ans[i].fi, ans[i].se), max(ans[i].fi, ans[i].se));

 	return 0;
}

