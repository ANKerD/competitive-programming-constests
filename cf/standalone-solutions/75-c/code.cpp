#include <bits/stdc++.h>
using namespace std;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

set<int> factor(int x) {
	set<int> ret;
	for (int i = 1; i <= sqrt(x+1); ++i) 
		if (x % i == 0)
			ret.insert(i),
			ret.insert(x/i);
	return ret;
}

int main(){
	int a,b;
	cin >> a >> b;
	set<int> sa = factor(a);
	vector<int> fa(sa.begin(), sa.end());
	set<int> sb = factor(b);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		auto it = lower_bound(fa.begin(), fa.end(), l);
		int ans = -1;
		while (it != fa.end() && *it <= r) {
			if (sb.count(*it)) 
				ans = *it;
			it++;
		}
		cout << ans << '\n';
	}
 	return 0;
}

