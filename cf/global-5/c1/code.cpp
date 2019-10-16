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
#define maxn 2101

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

struct pt {
	ll x,y,z,i;
	ll dist(pt &o) {
		ll dx = x - o.x;
		ll dy = y - o.y;
		ll dz = z - o.z;
		return dx * dx + dy * dy + dz * dz;
	}
};

pt O = {0,0,0};

bool cmp(pt &a, pt &b) {
	return O.dist(a) < O.dist(b);
}

const ll INF = 1e18+42;
bool vis[maxn];
pt a[maxn];

int main(){
	int n,x,y,z;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		a[i] = {x, y, x, i+1};
	}
	sort(a,a+n, cmp);
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		ll cur = INF, targ;

		for (int j = i+1; j < n; ++j) {
			if (vis[j]) continue;
			if (a[i].dist(a[j]) < cur)
				cur = a[i].dist(a[j]), targ = j;
		}
		vis[i] = vis[targ] = 1;
		trace(a[i].i, a[targ].i);
	}
 	return 0;
}

