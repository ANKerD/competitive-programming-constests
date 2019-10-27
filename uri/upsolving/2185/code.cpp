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
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn];
int st[maxn*4];
int acum[maxn*4];
int left(int x){return 2*x;}
int right(int x){return 2*x+1;}

inline void propagate(int id, int l, int r) {
	if (acum[id] == -1) return;
	if (l == r) {
		st[id] = acum[id];
	} else {
		st[id] = (r-l+1) % 2 ? acum[id] : 0;
		acum[left(id)] = acum[id];
		acum[right(id)] = acum[id];
	}
	acum[id] = -1;
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(left(id), l, mid);
	build(right(id), mid+1, r);
	st[id] = st[left(id)] ^ st[right(id)];
}

int query(int id, int l, int r, int bg, int nd) {
	propagate(id,l,r);
	if (l > nd || r < bg) return 0;
	if (bg <= l && r <= nd) return st[id];
	int mid = (l+r)/2;
	return 
		query(left(id), l, mid, bg, nd) ^
		query(right(id), mid+1, r, bg, nd);
}

void update(int id, int l, int r, int bg, int nd, int val) {
	propagate(id,l,r);
	if (l > nd || r < bg) return;
	if (bg <= l && r <= nd) {
		acum[id] = val;
		propagate(id, l, r);
		return;
	}
	int mid = (l+r)/2;
	update(left(id), l, mid, bg, nd, val);
	update(right(id), mid+1, r, bg, nd, val);
	st[id] = st[left(id)] ^ st[right(id)];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	
	build(1,1,n);
	// trace(n,m);
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		update(1,1,n,x,y,z);
		// trace(i);
		if (i == 3) {
			for (int j = 1; j <= n; ++j)
				trace(j,query(1,1,n,j,j));
			return 0;
		}
		if (query(1,1,n,1,n))
			trace("Possivel");
		else 
			trace("Impossivel");
	}
 	return 0;
}


