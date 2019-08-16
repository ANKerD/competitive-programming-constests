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
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn];

int main(){
	int n,m;
	while (1) {
		cin >> n >> m;
		if (n+m == 0) break;
		int s = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			s += a[i];
		}
		if (s == m) {
			trace(":D");
			continue;
		} else if (s < m) {
			trace("-.-");
			continue;
		}

		int tt = 200;
		long double l = 0, r = 1e4,ans=0;
		while (tt--) {
			ld t = 0;
			ld mid = (l+r)/2;
			for (int i = 0; i < n; ++i)
				if (mid < a[i])
					t += a[i]-mid;
			if (fabs(m-t) < 1e-9) {
				l = ans = mid;
				break;
			} if (t > m) {
				l = ans = mid;
			} else r = mid;
		}

		cout << fixed << setprecision(4) << ans << '\n';
	}
 	return 0;
}

