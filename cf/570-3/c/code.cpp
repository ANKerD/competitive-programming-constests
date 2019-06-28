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
#define int long long
template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int32_t main(){
	int q,n,k,a,b;
	cin >> q;
	while (q--) {
		cin >> k >> n >> a >> b;
		if (n*b >= k) {
			cout << "-1\n";
			continue;
		}
		int l = 0, r = n;
		while (l <= r) {
			int mid = (l+r)>>1;
			if (a*mid+(n-mid)*b < k)
				l = mid+1;
			else
				r = mid-1;
		}
		cout << r << '\n';
	}
 	return 0;
}

