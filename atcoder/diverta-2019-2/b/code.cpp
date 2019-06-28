#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<ll, ll>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ii a[60];
int used[60];
map<ii, int> dots;
set<ii> pq;

int main(){
	int n,x,y,dx,dy;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		// trace(x,y);
		dots[mp(x,y)] = i;
		a[i] = mp(x,y);
	}
	int ans = 0;
	memset(used, 0, sizeof used);
	// trace("hito");
	for (int i = 1; i <= n; ++i) {
		used[i] = 1;
		++ans;
		for (int j = 1+i; j <= n; ++j) {
			if (used[i]) continue;
			dx = a[i].x - a[j].x;
			dy = a[i].y - a[j].y;
			used[j] = 1;
			x = a[j].x+dx,
			y = a[j].y+dy;
			trace(x,y,dx,dy);
			while (dots[mp(x,y)] > 1 && dots[mp(x,y)] < x) {
				// trace("misera");
				used[dots[mp(x,y)]] = 1;
				x += dx;
				y += dy;
			}
			dx = a[j].x - a[i].x;
			dy = a[j].y - a[i].y;
			x = a[i].x-dx,
			y = a[i].y-dy;
			while (dots[mp(x,y)] > 1 && dots[mp(x,y)] < x) {
				// trace("misera");
				used[dots[mp(x,y)]] = 1;
				x -= dx;
				y -= dy;
			}
			// trace(x,y,dx,dy);
			break;
		}
	}
	trace(ans);
 	return 0;
}

