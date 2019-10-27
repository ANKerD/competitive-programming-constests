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
	int n,x;
	while (true) {
		cin >> n;
		if (!n) break;
		vi a;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			a.push_back(x);
		}
		ll ans = 0, ac = 0;
		for (auto u: a) {
			ans += abs(ac);
			ac += u;
		}
		trace(ans);
	}
 	return 0;
}

