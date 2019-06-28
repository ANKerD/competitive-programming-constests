#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
ll arr[maxn];
ll qq[maxn];

void update(int i, ll v, ll st[maxn]) {
	for(;i < maxn; i += i&-i)
		st[i] += v;
}

ll query(int i, ll st[maxn]) {
	ll ans = 0;
	for (;i; i-=i&-i)
		ans += st[i];
	return ans;
}

struct Q {
	ll l,r,d;
};

Q q[maxn];

int main(){
	int n,m,k,x;
	cin >> n >> m >> k;
	memset(arr, 0, sizeof arr);
	memset(qq, 0, sizeof qq);
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		update(i, x, arr);
		update(i+1, -x, arr);
	}

	for (int i = 1; i <= m; ++i)
		cin >> q[i].l >> q[i].r >> q[i].d;

	for (int i = 1; i <= k; ++i) {
		ll x,y;
		cin >> x >> y;
		update(x, 1, qq);
		update(y+1, -1, qq);
	}

	for (int i = 1; i <= m; ++i) {
		update(q[i].l, query(i, qq)*q[i].d, arr);
		update(q[i].r+1, -query(i, qq)*q[i].d, arr);
	}

	for (int i = 1; i <= n; ++i)
		printf("%lld%c", query(i, arr), " \n"[i==n]);

 	return 0;
}

