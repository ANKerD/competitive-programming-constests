#include <bits/stdc++.h>
using namespace std;
#define loopall for (register int i = 1; i <= foo; ++i)
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
vi st[maxn*4];
int left(int x){return 2*x;}
int right(int x){return 2*x+1;}
int n,m,foo;

void inline cls(vi &a) {
	for (int i = 1; i <= foo; ++i)
		a[i] = 0;
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id][a[l]] = 1;
		return;
	}
	int mid = (l+r)/2;
	build(left(id), l, mid);
	build(right(id), mid+1, r);
	loopall
		st[id][i] = st[left(id)][i] + st[right(id)][i];
}

vi ret(52);
vi query(int id, int l, int r, int bg, int nd) {
	// trace(id,l,r,bg,nd);
	if (l > nd || r < bg) {
		return ret;
	}
	if (bg <= l && r <= nd) return st[id];
	int mid = (l+r)/2;
	vi a = query(left(id), l, mid, bg, nd),
	   b = query(right(id), mid+1, r, bg, nd);
	loopall
		a[i] = a[i] + b[i];
	return a;
}

void update(int id, int l, int r, int idx, int val) {
	if (l == r) {
		cls(st[id]);
		st[id][val] = 1;
		return;
	}
	int mid = (l+r)>>1;
	if (idx <= mid)
		update(left(id), l, mid, idx, val);
	else
		update(right(id), mid+1, r, idx, val);
	loopall
		st[id][i] = st[left(id)][i] + st[right(id)][i];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> foo;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	for (int i = 1; i < 4*n; ++i) 
		st[i].resize(foo+2);
	// trace(n,m,foo);
	build(1,1,n);
	int op, x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> op >> x >> y;
		if (op == 2) {
			update(1,1,n,x,y);
		} else {
			// trace("disgraccccaaaaa");
			int ans = 0;
			for (auto u: query(1,1,n,x,y))
				if (u) ++ans;
			trace(ans);
			// if (!x) cout << '0';
			// else if (x > 0) cout << '+';
			// else cout << '-';
		}
	}

 	return 0;
}

