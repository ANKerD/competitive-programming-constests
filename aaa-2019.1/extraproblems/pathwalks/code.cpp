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

struct Segtree {
	int v;
	Segtree *left, *right;
	Segtree(){ left = right = NULL; v = 0;}
};

void inline xtend(Segtree *node) {
	if (node->left == NULL)
		node->left = new Segtree();
	if (node->right == NULL)
		node->right = new Segtree();
}

int query(Segtree *node, int l, int r, int bg, int nd) {
	xtend(node);
	if (l >= bg && r <= nd)
		return node->v;
	if (l > nd || r < bg)
		return 0;

	int mid = (l+r)>>1;
	return max(
		query(node->left, l, mid, bg, nd),
		query(node->right, mid+1, r, bg, nd)
	);
}

void update(Segtree *node, int l, int r, int pos, int v) {
	xtend(node);
	if (l == r) {
		node->v = max(node->v, v);
		return;
	}
	int mid = (l+r)>>1;
	if (pos <= mid)
		update(node->left, l, mid, pos, v);
	else
		update(node->right, mid+1, r, pos, v);
	node->v = max(node->left->v, node->right->v);
}

Segtree* g[maxn];

int query(int node, int l) {
	return query(g[node], 1, maxn, l, maxn);
}

void update(int node, int pos, int v) {
	update(g[node], 1, maxn, pos, v);
}

int main(){
	int n, m;
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; ++i)
		g[i] = new Segtree();
	
	vector<pair<ii, int> > edges;
	int x,y,z;
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d\n", &x, &y, &z);
		edges.push_back(mp(mp(x,y), z));
	}
	reverse(edges.begin(), edges.end());
	int ans = 1;
	for (int i = 0; i < m; ++i) {
		x = edges[i].fi.fi;
		y = edges[i].fi.se;
		z = edges[i].se;
		int pt = query(y, z+1);
		update(x, z, pt+1);
		ans = max(ans, pt+1);
	}
	printf("%d\n", ans);
 	return 0;
}

