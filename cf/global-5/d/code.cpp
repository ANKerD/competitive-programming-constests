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
#define maxn 300010
#define LIMIT 1000000010
#define NEUTRAL 3*n

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int ans[maxn];
int a[maxn];
int n;

struct Seg {
	int v;
	Seg *L, *R;
	Seg() {
		L = R = NULL;
		v = NEUTRAL;
	};
};

inline void extend(Seg *node) {
	if (node->L == NULL)
		node->L = new Seg();
	if (node->R == NULL)
		node->R = new Seg();
}

void update(Seg *node, int index, int val, int l = 0, int r = LIMIT) {
	extend(node);
	if (l == r) {
		// trace("up", index, val, l, r);
		node->v = val;
		return;
	}
	int mid = (l+r)/2;
	if (index <= mid)
		update(node->L, index, val, l, mid);
	else
		update(node->R, index, val, mid+1, r);
	node->v = min(node->L->v, node->R->v);
}

int query(Seg *node, int beg, int nd, int l = 0, int r = LIMIT) {
	// trace(l,r, node);
	extend(node);
	if (beg <= l && r <= nd)
		return node->v;
	if (nd < l || beg > r) 
		return NEUTRAL;
	int mid = (l+r)/2;
	return min(
		query(node->L, beg, nd, l, mid),
		query(node->R, beg, nd, mid+1, r)
	);
}

int main(){
	cin >> n;
	int mi = 1e9 + 10, mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i+n+n] = a[i+n] = a[i];
		mi = min(mi, a[i]);
		mx = max(mx, a[i]);
	}

	if (mx < mi*2+1) {
		for (int i = 0; i < n; ++i)
			cout << -1 << " \n"[i+1 == n];
		return 0;
	}

	ans[NEUTRAL] = 0;
	a[NEUTRAL] = LIMIT+1;
	mx = 0;
	
	Seg *seg = new Seg();
	for (int i = NEUTRAL-1; i+1; --i) {
		if (a[i] <= a[i + 1]) {
			ans[i] = 1 + ans[i + 1];
		} else {
			int tmp = query(seg, 0, (a[i] - 1) / 2);
			ans[i] = min(tmp - i, 1 + ans[i + 1]);
		}
		update(seg, a[i], i);
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << " \n"[i+1 == n];

 	return 0;
}

