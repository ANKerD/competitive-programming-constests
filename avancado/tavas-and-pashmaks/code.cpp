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

struct pt {
	int x,y;
	int operator ^ (pt o) { return x * o.y - y * o.x;}
	pt operator -(pt o) {
		return {x - o.x, y - o.y};
	}
};

inline bool operator <(const pt &a, const pt &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool ccw(pt p, pt q, pt r) {
	pt p1 = q-p;
	pt p2 = r-p;
	return (p1 ^ p2) > 0;
}

vector<pt> convexhull(vector<pt> points) {
	int n = (int) points.size();
	if (n <= 3) return points;

	sort(points.begin(), points.end());

	int k = 0;
	vector<pt> hull(2*n);

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && ccw(hull[k-2], hull[k-1], points[i])) k--;
		hull[k++] = points[i];
	}

	for (int i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && ccw(hull[k-2], hull[k-1], points[i-1])) k--;
		hull[k++] = points[i-1];
	}

	hull.resize(k-1);
	return hull;
}

int sz,x,y,mx=0,my=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<ii, vi> dots;
	set<ii> points;
	cin >> sz;
	for (int i = 0; i < sz; ++i) {
		cin >> x >> y;
		points.insert({x, y});
		dots[{x,y}].pb(i+1);
		mx = max(x, mx);
		my = max(y, my);
	}
	points.insert({0, my});
	points.insert({mx, 0});
	points.insert({0, 0});

	vector<pt> setofpoints;
	for (auto u: points)
		setofpoints.pb({u.fi, u.se});
		
	vector<pt> hull = convexhull(setofpoints);
	set<int> aux;
	for (auto u: hull)
		for (auto g: dots[mp(u.x, u.y)])
			aux.insert(g);

	vi ans = vi(aux.begin(), aux.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " \n"[i+1 == ans.size()];

 	return 0;
}

