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

ll get(ll x) {
	switch(x) {
		case 1LL:
		case 2LL:
			return 0;
		case 3LL:
			return 2;
		case 4LL:
			return 3;
		default:
			break;
	}
	ll ans = 3;
	x -= 4;
	ans += (x/3)*2;
	if (x%3 == 2) ans++;
	// if (x % 3 == 0) {
	// 	ans += x/3*2;
	// } else if (x % 3 == 2) {
	// 	ans += (x/3-1)*2+1;
	// } else {
	// 	ans += (x/3-1)*2;
	// }
	return ans;
}

int main(){
	int n,t;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << get(n) << '\n';
	}
 	return 0;
}

