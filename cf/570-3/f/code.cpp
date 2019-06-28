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

int a[maxn];
int n;

bitset<maxn> p;
vi f[maxn];

bool cmp(int a, int b) {
	for (int i = 0; i < min(f[a].size(), f[b].size()); ++i)
		if (f[a][i] != f[b][i])
			return f[a][i] < f[b][i];
	return a > b;
}

int main(){
	p.set();
	register int i = 2;
	register int j;
	while (i < maxn) {
		f[i].pb(i);
		j = i<<1;
		while (j < maxn) {
			p[j] = 0;
			f[j].pb(i);
			j += i;
		}
		++i;
		while (i < maxn && !p[i])
			++i;
	}

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int q;
	cin >> q;

	while (q--) {
		cin >> n;
		for (int i = 0; i < n; ++i)	{
			cin >> a[i];
		}
		sort(a,a+n, cmp);
		// for (int i = 0; i < n; ++i)
		// 	trace(a[i]);
		// trace("-------");
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, a[i]);
			for (int j = i+1; j < n; ++j) {
				if (a[i] % a[j] == 0) continue;
				ans = max(ans, a[i] + a[j]);
				for (int k = j+1; k < n; ++k) {
					if (a[i] % a[k] == 0 || a[j] % a[k] == 0) continue;
					ans = max(ans, a[i] + a[j] + a[k]);
				}	
			}
		}
		cout << ans << '\n';
	}
 	return 0;
}

