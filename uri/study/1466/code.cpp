#include <bits/stdc++.h>
using namespace std;
#define GHOST -1898
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

struct bst {
	int v;
	bst *l, *r;
	bst(){l = r = NULL; v = GHOST;}
};

void inline extend(bst *node) {
	if (node->v == GHOST) {
		node->l = new bst();
		node->r = new bst();
	}
}

void insert(bst *node, int v) {
	extend(node);
	if (node->v == GHOST) {
		node->v = v;
		return;
	}
	if (v < node->v) 
		insert(node->l, v);
	else
		insert(node->r, v);
}

int main() {
	int t,n,x;
	cin >> t;
	// trace(t);
	for (int cnt = 1; cnt <= t; ++cnt) {
		cin >> n;
		bst *root = new bst();
		for (int i = 0; i < n; ++i) {
			cin >> x;
			insert(root, x);
		}
		queue<bst*> q;
		q.push(root);
		vi ans;
		while (!q.empty()) {
			bst *top = q.front();
			q.pop();
			if (top->v == GHOST) continue;
			ans.push_back(top->v);
			q.push(top->l);
			q.push(top->r);
		}
		printf("Case %d:\n", cnt);
		for (int i = 0; i < n; ++i)
			cout << ans[i] << " \n"[i+1==n];
		cout << "\n";
	}
	return 0;
}