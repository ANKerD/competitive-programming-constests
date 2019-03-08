#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 1000000000LL
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
#define pnode node*
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

template<typename T>
void trace(T a){
	cout << a << '\n';
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << ' ';
	trace(args...);
}

struct node {
	int v;
	int acum;
	pnode l;
	pnode r;
	node(){ node(0); };
	node(int _v){
		v = _v;
		acum = 0;
		l = r = NULL;
	};
};

pnode newNode(int v){
	return new node(v);
}

void extend(pnode p){
	if(!p->l) p->l = newNode(0);
	if(!p->r) p->r = newNode(0);
}

void update(pnode root, int l, int r, int bg, int nd){
	// trace(l, r, root->v);
	if(bg > r || nd < l) return;

	extend(root);

	if(l >= bg && r <= nd){
		root->v += (1+root->acum) * max(0LL, r-l+1);
		root->l->acum += 1+root->acum;
		root->r->acum += 1+root->acum;
		root->acum = 0;
		return;
	}

	int m = (r+l)/2;
	
	update(root->l, l, m, bg, nd);
	update(root->r, m+1, r, bg, nd);
	
	root->v = root->l->v+root->r->v;
}

// int depth = 5;
int query(pnode root, int l, int r, int pos){
	if(pos > r || pos < l) return 0;

	extend(root);

	root->v += root->acum * max(0LL, r-l+1);
	root->l->acum += root->acum;
	root->r->acum += root->acum;
	root->acum = 0;

	if(l == r && r == pos){
		return root->v;
	}

	int m = (l+r)/2;
	
	return query(root->l, l, m, pos) + query(root->r, m+1, r, pos);
}

int32_t main(){
	
	pnode root = newNode(0);
	
	int ans = 0;
	int n,a;
	cin >> n;
	range(n){
		cin >> a;
		ans += query(root, 1, maxn, 1+i);
		update(root, 1, maxn, 1, a);
	}
	
	trace(ans);

 	return 0;
}