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
int left(int x){return 2*x;}
int right(int x){return 2*x+1;}

void build(int id, int l, int r) {
	// trace(id, l, r);
	if (l == r) {
		st[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(left(id), l, mid);
	build(right(id), mid+1, r);
	st[id] = st[left(id)] * st[right(id)];
}

int query(int id, int l, int r, int bg, int nd) {
	if (l > nd || r < bg) return 1;
	if (bg <= l && r <= nd) return st[id];
	int mid = (l+r)/2;
	return 
		query(left(id), l, mid, bg, nd) *
		query(right(id), mid+1, r, bg, nd);
}

void update(int id, int l, int r, int idx, int val) {
	if (l == r) {
		st[id] = val;
		return;
	}
	int mid = (l+r)/2;
	if (idx <= mid)
		update(left(id), l, mid, idx, val);
	else
		update(right(id), mid+1, r, idx, val);
	st[id] = st[left(id)] * st[right(id)];
}

inline void get(int &x) {
	if (x) x = x > 0 ? 1 : -1;
}

int main(){
	int n,m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			get(a[i]);
		}
		build(1,1,n);
		for (int i = 1; i <= m; ++i) {
			char op; int x, y;
			cin >> op >> x >> y;
			if (op == 'C') {
				get(y);
				update(1,1,n,x,y);
			} else {
				x = query(1,1,n,x,y);
				if (!x) cout << '0';
				else if (x > 0) cout << '+';
				else cout << '-';
			}
		}
		cout << '\n';
		// break;
	}

 	return 0;
}


