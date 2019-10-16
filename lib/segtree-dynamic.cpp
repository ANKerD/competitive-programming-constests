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
