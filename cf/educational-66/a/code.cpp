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
int solve(int n, int k) {
	// trace(n,k);
	if (n < 0) return 1e5;
	if (n == 0) return 0;
	if (n % k) {
		// trace(n, n - n%k, k);
		if (n > k)
			return n%k + solve(n - n%k, k);
		return n;
	}
	return 1 + solve(n/k, k);
}

int32_t main(){
	int t;
	cin >> t;
	while (t--) {
		int k;

		int n;
		cin >> n >> k;
		cout << solve(n, k) << '\n';
	}

 	return 0;
}

