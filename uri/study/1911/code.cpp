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

int main(){
	while (true) {
		int n,m;
		cin >> n;
		if (!n) break;
		map<string, string> t;
		string x,y;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			t[x] = y;
		}
		cin >> m;
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			if (t[x] != y) {
				trace(t[x], y);
				ans++;
			}
		}
		trace(ans);
	}
 	return 0;
}