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
	ll n,m,k,x;
	cin >> n >> m >> k;
	queue<ll> q;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		q.push(x);
	}
	ll dec = 0;
	ll ans = 0;
	while (!q.empty()) {
		ll rem = 0;
		ll st = (q.front()-dec+k-1) / k;
		while (!q.empty() && (q.front()-dec+k-1) / k == st) {
			q.pop();
			++rem;
		}
		++ans;
		dec += rem;
	}

	cout << ans << '\n';
 	return 0;
}

