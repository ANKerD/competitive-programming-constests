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
#define block 225
//#define block 2

template<typename T>
void trace(T a){ cerr << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cerr << a << ' '; trace(args...);}

int p[maxn];
vi f[maxn];
int ans[maxn/block+2][maxn];
int a[maxn];

inline void update(int idx, int val, int ins=1) {
	int bid = idx/block;
	int comb, t, j;
	int mask = (1<<f[val].size())-1;
	for (int s=mask; s; s=(s-1)&mask) {
		comb = 1;
		j = s;
		t = 0;
		while (j) {
			if (j&(1<<t))
				comb *= f[val][t];
			j >>=1;
			++t;
		}
		ans[bid][comb] += ins;
	}
}

inline int getval(int bl, int z){
	int res = 0;
	int mask = (1<<f[z].size())-1;
	for (int j=mask; j; j=(j-1)&mask) {
		int k = j, bit = 0, tmp = 1;
		while (k) {
			if (k & (1<<bit))
				tmp *= f[z][bit];
			bit++;
			k >>= 1;
		}
		if (__builtin_popcount(j)&1)
			res += ans[bl][tmp];
		else
			res -= ans[bl][tmp];
	}
	return res;
};

int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b%a, a);
}

int inline query(int l, int r, int z) {
	int ans = 0;
	for (int i = l; i <= r; ) {
		if (i % block == 0 and i+block <= r) {
			ans += getval(i/block, z);
			i += block;
		} else {
			if (gcd(z, a[i])!=1)
				ans++;
			i++;
		}
	}
	return ans;
}

inline void fastscan(int &x) {
	register int c;
	x =0;
	c=getchar();
	for(;(c>47 && c<58);c=getchar())
		x = (x<<1) + (x<<3) +c -48;
}

int main(){
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	int i = 2, j;
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
	fastscan(n);
	for (int i = 1; i <= n; ++i) {
		fastscan(a[i]);
		update(i, a[i]);
	}
	int q,x,y,z,k;
	fastscan(q);
	vi answer;
	while(q--) {
		// if (q < 20000)
		// 	assert(0);
		fastscan(x);
		fastscan(y);
		fastscan(z);
		if (x == 1) {
			update(y, a[y], -1);
			a[y] = z;
			update(y, a[y]);
		} else {
			fastscan(k);
			answer.pb(z-y+1-query(y,z,k));
		}
	}
	for (auto u: answer)
		printf("%d\n", u);

 	return 0;
}
