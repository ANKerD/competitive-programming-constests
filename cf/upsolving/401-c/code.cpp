#include <bits/stdc++.h>
using namespace std;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> ans;
	if (n <= m+1 && m <= 2*n+2) {
		if (n == m+1) {
			n--;
			ans.push_back(0);
		}
		while (n && m >= 2 && m > n) {
			ans.push_back(1);
			ans.push_back(1);
			ans.push_back(0);
			n--;
			m -= 2;
		}
		while (n > 0 && n == m) {
			ans.push_back(1);
			ans.push_back(0);
			n--;
			m--;
		}
		while (m) {
			ans.push_back(1);
			m--;
		}
		for (auto u: ans) cout << u;
	} else trace(-1);
 	return 0;
}

