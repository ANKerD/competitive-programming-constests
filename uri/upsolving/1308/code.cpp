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
	ll t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		int ret;
		ll l = 0, r = 2e9+10;
		while (l <= r) {
			ll mid = (l+r)/2LL;
			if (mid*(mid+1) == 2*n) {
				ret = mid;
				r = mid-1;
				break;
			} else if (mid*(mid+1) >= 2*n) {
				ret = mid-1;
				r = mid-1;
				// break;
			} else l = mid+1;
		}
		trace(ret);
	}
 	return 0;
}

