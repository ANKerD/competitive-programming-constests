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
// #define block 225
#define block 6

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int p[maxn];
vi f[maxn];
int ans[block+10][maxn/2];
int a[maxn];

inline void update(int idx, int val, int comb=1, int ins=1, int mask=0, int i = 0) {
	if ((1<<i)&mask) return;
	if (i >= f[val].size()) return;
	
	update(idx, val, comb, ins, mask, i+1);
	int bid = idx/block;
	comb *= f[val][i];
	ans[bid][comb] += ins;
	update(idx, val, comb, ins, (1<<i)|mask, i+1);
}

int getval(int bl, int z, int comb=1, int mask=0, int i = 0){
	if ((1<<i)&mask) return 0;
	if (i >= f[z].size()) return 0;
	
	int tmp = getval(bl, z, comb, mask, i+1);
	comb *= f[z][i];
	tmp += ans[bl][comb];
	tmp -= getval(bl, z, comb, mask|(1<<i), i+1);
	return tmp;
};

int query(int l, int r, int z) {
	//
}

int main(){

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	register int i = 2, j;
	while (i < maxn) {
		f[i].push_back(i);
		j = i<<1;
		while (j < maxn) {
			p[j] = 0;
			f[j].push_back(i);
			j += i;
		}
		++i;
		while (i < maxn && !p[i]) 
			++i;
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(i, a[i]);
	}

	int q,x,y,z,k;
	cin >> q;
	while(q--) {
		cin >> x >> y >> z;
		if (x == 1) {
			update(y, a[y], 1,-1);
			a[y] = z;
			update(y, a[y]);
		} else {
			cin >> k;
			cout << z-y+1-query(y,z,k) << '\n';
		}
	}

 	return 0;
}

