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
#define midif int mid = (l+r)>>1; if (idx <= mid)

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int st[4*maxn];
int lazy[4*maxn];
inline int left(int x) {return 2*x;}
inline int right(int x) {return 2*x+1;}

void inline propagate(int id, int l, int r) {
	if (lazy[id]) {
		int top = lazy[id];
		if (l == r) {
			// trace(st[id], top);
			st[id] = max(st[id], top);
		} else {
			lazy[left(id)] = max(lazy[left(id)], top);
			lazy[right(id)] = max(lazy[right(id)], top);
		}
		lazy[id] = 0;
	}
}

void update(int id, int l, int r, int idx, int val) {
	propagate(id, l, r);
	if (l == r) {
		st[id] = val;
		return;
	}
	midif
		update(left(id), l, mid, idx, val);
	else
		update(right(id), mid+1, r, idx, val);
}


void rageset(int id, int l, int r, int bg, int nd, int val) {
	propagate(id, l, r);
	if (r < bg || l > nd) return;
	if (l >= bg && r <= nd) {
		lazy[id] = val;
		return;
	}
	int mid = (l+r)>>1;
	rageset(left(id), l, mid, bg, nd, val);
	rageset(right(id), mid+1, r, bg, nd, val);
}

int query(int id, int l, int r, int idx) {
	propagate(id, l, r);
	if (l == r) {
		return st[id];
	}
	midif
		return query(left(id), l, mid, idx);
	else
		return query(right(id), mid+1, r, idx);
}

int main(){
	int n,x,q;
	for (int i = 0; i < 4*maxn; ++i) {
		lazy[i] = st[i] = 0;
		// while (!lazy[i].empty())
		// 	lazy[i].pop();
	}
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		update(1,1,n,i,x);
	}
	cin >> q;
	int op, idx, value;
	while (q--) {
		cin >> op;
		if (op == 2) {
			cin >> value;
			rageset(1, 1, n, 1, n, value);
		} else {
			cin >> idx >> value;
			update(1, 1, n, idx, value);
		}

	}
	for (int i = 1; i <= n; ++i)
		cout << query(1, 1, n, i) << " \n"[i == n];

 	return 0;
}

