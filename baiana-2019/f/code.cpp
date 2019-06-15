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
#define maxn 110

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

char a[maxn][maxn];

int main(){
	int n,m;
	vii ans;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char x;
			cin >> x;
			if (x != a[i][j])
				ans.push_back(mp(i+1, j+1));
		}

	for (int i = 0; i < ans.size(); ++i)
		printf("%d %d\n", ans[i].fi, ans[i].se);

 	return 0;
}

