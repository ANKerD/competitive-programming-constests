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
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int f[20];

int main(){
	std::set<int> ans;
	int x;
	for (int i = 0; i < 6; ++i) {
		cin >> x;
		ans.insert(x);
	}
	int n, m, cur;
	memset(f,0,sizeof f);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		cur = 0;
		for (int j = 0; j < m; ++j) {
			cin >> x;
			if (ans.count(x)) {
				++cur;
			}
		}
		if (cur > 6) {
			trace(")---");
			return 0;
		}
		++f[cur];
	}
	printf("%d %d %d\n", f[6], f[5], f[4]);
 	return 0;
}

