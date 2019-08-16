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

int p[maxn];

int find(int x){
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

int join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) p[y] = x;
}

int main(){
	int n,m,x,y,z;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	priority_queue< pair<int, ii> > q;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		q.push({-z, {x,y}});
	}

	int ans = 0;

	while (!q.empty()) {
		int cost = -q.top().fi;
		x = q.top().se.fi;
		y = q.top().se.se;
		q.pop();
		if (find(x) != find(y)) {
			ans += cost;
			join(x,y);
		}
	}
	trace(ans);
 	return 0;
}

