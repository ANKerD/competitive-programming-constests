#include <bits/stdc++.h>
using namespace std;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){
	string s;
	cin >> s;
	vector<char> ans;
	for (int i = 0; i < min(2, (int) s.size()); ++i)
		ans.push_back(s[i]);
	for (int i = 2; i < s.size(); ++i) {
		int sz = ans.size();
		if (s[i] == ans[sz-1] && ans[sz-1] == ans[sz-2]) continue;
		if (i >= 3 && s[i] == ans[sz-1] && ans[sz-3] == ans[sz-2]) continue;
		ans.push_back(s[i]);
	}
	for (auto u: ans) cout << u;
	cout << '\n';
 	return 0;
}

