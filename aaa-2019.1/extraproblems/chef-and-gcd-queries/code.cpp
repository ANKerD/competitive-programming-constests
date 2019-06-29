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
#define block 250
// #define block 6

template<typename T>
void trace(T a){ cerr << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cerr << a << ' '; trace(args...);}

int p[maxn];
vi f[maxn];
int ans[max(block, maxn/block+2)][maxn];
int a[maxn];

inline void update(int idx, int val, int ins=1) {
	int bid = idx/block;
	int mask = (1<<f[val].size()) - 1;
	for (int s=mask; s; s=(s-1)&mask) {
		int comb = 1, sub = s, pos = 0;
		while (sub) {
			comb *= (sub & 1) ? f[val][pos] : 1;
			sub = sub >> 1;
			++pos;
		}
		ans[bid][comb] += ins;
	}
}

inline int getval(int bl, int z){
	int res = 0;
	int mask = (1<<f[z].size()) - 1;
	for (int s=mask; s; s=(s-1)&mask) {
		int sub = s, comb = 1, pos = 0;
		while (sub) {
			comb *= (sub & 1) ? f[z][pos] : 1;
			sub = sub >> 1;
			++pos;
		}
		if (__builtin_popcount(s) & 1)
			res += ans[bl][comb];
		else
			res -= ans[bl][comb];
	}
	return res;
};

int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b%a, a);
}

int query(int l, int r, int z) {
	int ans = 0;
	for (int i = l; i <= r;) {
		if (i % block == 0 && i+block<=r) {
			ans += getval(i/block, z);
			i += block;
		} else {
			if (__gcd(a[i], z) != 1)
				++ans;
			++i;
		}
	}
	return ans;
}

int inline query(int l, int r, int z) {
	int ans = 0;
	while(l <= r) {
		if (l % block == 0 and l+block <= r+1) {
			ans += getval(l/block, z);
			l += block;
		} else {
			if (gcd(z, a[l])!=1)
				ans++;
			l++;
		}
	}
	return ans;
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
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		update(i, a[i]);
	}
	int q,x,y,z,k;
	scanf("%d", &q);
	vi answer;
	while(q--) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			update(y, a[y], -1);
			a[y] = z;
			update(y, a[y]);
		} else {
			scanf("%d", &k);
			answer.pb(z-y+1-query(y,z,k));
		}
	}
	for (auto u: answer)
		printf("%d\n", u);

 	return 0;
}