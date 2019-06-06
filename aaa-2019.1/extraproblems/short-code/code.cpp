#include <bits/stdc++.h>
#define sint multiset<int>
using namespace std;

struct trie {
	bool nd = 0;
	map<char, trie> next;
	void add(string &s, int i = 0) {
		if (i == s.size()) {
			nd = 1;
			return;
		}
		next[s[i]].add(s, i+1);
	}
	sint solve(int sz = 0) {
		sint ans;
		for (auto &child : this->next) {
			sint sub = child.second.solve(sz+1);
			if (ans.size() < sub.size())
				swap(ans, sub);
			for (auto v : sub)
				ans.insert(v);
		}
		if (nd) {
			ans.insert(sz);
		} else if (sz) {
			auto it = ans.end(); --it;
			ans.erase(it);
			ans.insert(sz);
		}
		return ans;
	}
} root;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		root.add(s);
	}
	sint ans = root.solve();
	cout << accumulate(ans.begin(), ans.end(), 0) << '\n';

 	return 0;
}

