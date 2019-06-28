#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int st[maxn];
int cnt = 0, n;

inline void update(int id, int val) {
	for (; id <= n; id += id&-id)
		st[id] = max(st[id], val);
}

int query(int id) {
	int ans = 0;
	for (; id; id-=id&-id)
		ans = max(ans,st[id]);
	return ans;
}

int a[maxn];

int main(){
	cin >> n;
	int sz = 1;
	a[0] = n+10;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int that = query(a[i]-1)+1;
		cnt = max(cnt, that);
		update(a[i], that);
	}
	cout << cnt << '\n';
 	return 0;
}

