#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
priority_queue<int> a[maxn];

int main(){
	int n,m,x,y;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x <= m)
			a[m-x].push(y);
	}
	int ans = 0;
	for (int i = m; i >= 0; --i) {
		if (a[i].empty()) continue;
		ans += a[i].top();
		a[i].pop();
		for (int j = i-1; !a[i].empty() && j >= 0; --j) {
			a[j].push(a[i].top());
			a[i].pop();
		}
	}
	cout << ans << '\n';
 	return 0;
}

