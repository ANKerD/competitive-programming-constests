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

struct up {
	int i, a, k;
	char c;
	bool operator == (up o) {
		return o.i == i && o.a == a && o.k == k;
	}
};

up NIL = {-1, -1, -1};

up acum[maxn];
char st[maxn];
string a;
int n;
	
int left(int x) {return x<<1;}
int right(int x) {return (x<<1)|1;}

void build(int id, int l, int r) {
	if (l == r) {
		acum[id] = NIL;
		st[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(left(id), l, mid);
	build(left(id), mid+1, r);
}

inline void propagate(int id, int l, int r) {
	// if (!(acum[id] == NIL)) {
	if (false) {
		if (l == r) {
			if (l >= acum[id].i && 
			(l - acum[id].i) % acum[id].a == 0 && 
			(l - acum[id].i) / acum[id].a <= acum[id].k) {
				st[id] = acum[id].c;
			}
		} else {
			acum[left(id)] = acum[id];
			acum[right(id)] = acum[id];
		}
	}
	acum[id] = NIL;
}

char query(int id, int l, int r, int index) {
	propagate(id, l, r);
	if (l == r) return st[id];
	int mid = (l+r)/2;
	if (index <= mid)
		return query(left(id), l, mid, index);
	else
		return query(right(id), mid+1, r, index);
}

// void update(int id, int l, int r, int bg, int nd) {
// 	propagate(id, l, r);
// }

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){	
	cin >> a;
	n = a.size();
	build(1,1,n);
	for (int i = 1; i <= n; ++i)
		cout << query(1, 1, n, i);
	cout << '\n';
 	return 0;
}


