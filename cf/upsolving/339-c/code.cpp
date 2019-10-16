#include <bits/stdc++.h>
using namespace std;
#define maxn 1010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int dp[11][11][maxn];
int go[11][11][maxn];
string s;
int m;

bool solve(int diff, int last, int left) {
	if (!left) return true;
	// trace(diff, last, left);
	int &ans = dp[diff][last][left];
	int &gg = go[diff][last][left];
	if (ans != -1) return ans;
	ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i+1 == last || s[i] == '0') continue;
		if (i+1 > diff && solve(i+1-diff, i+1, left-1)) {
			ans = 1;
			gg = i+1;
			break;
		}
	}
	return ans;
}

int main(){
	memset(dp, -1, sizeof dp);
	cin >> s >> m;
	if (solve(0, 0, m)) {
		cout << "Yes\n";
		vector<int> ans;
		int diff, last, left;
		diff = last = 0;
		left = m;
		while (left) {
			int &gg = go[diff][last][left];
			ans.push_back(gg);
			diff = gg-diff;
			last = gg;
			left--;
		}
		for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i+1==ans.size()];
	} else cout << "No\n";
 	return 0;
}

