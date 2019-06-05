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

int n,a,b,x,y;

vi go(int st, int nd, int d) {
	vi path;
	path.pb(st);
	// trace(st,nd,d);
	while (st != nd) {
		path.pb(st);
		st += d;
		if (st > n) st = 1;
		if (!st) st = n;
		path.pb(st);
	}
	// for (auto u: path)
	// 	cout << u << ' ';
	// cout << '\n';
	return path;
}

bool check(vi q, vi w) {
	for (int i = 0; i < min((int)q.size(), (int)w.size()); ++i)
		if (q[i] == w[i])
			return true;
	return false;
}

int main(){
	cin >> n >> a >> x >> b >> y;
	// vi q,w;
	// trace(n,a,x);
	bool ok = false;
	ok = ok || check(go(a,x,1),go(b,y,1));
	ok = ok || check(go(a,x,1),go(b,y,-1));
	ok = ok || check(go(a,x,-1),go(b,y,1));
	ok = ok || check(go(a,x,-1),go(b,y,-1));
	if (ok) 
		cout << "yes\n";
	else
		cout << "no\n";
 	return 0;
}

