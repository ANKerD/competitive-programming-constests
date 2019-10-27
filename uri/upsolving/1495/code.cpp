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
	int n,g;
	while (scanf("%d %d", &n, &g) != EOF) {
		priority_queue<int> q;
		int ans = 0,s,r, emp = 0;
		vi a;
		for (int i = 0; i < n; ++i) {
			cin >> s >> r;
			if (s > r) 
				ans += 3;
			else if (s == r) {
				ans += 1;
				++emp;
			} else {
				a.push_back(r-s+1);
			}
		}
		sort(a.begin(), a.end());
		for (int j = 1; j < a.size(); ++j)
			a[j] += a[j-1];
		int st = ans;
		ans = ans + 2*min(emp, g);
		for (int j = 0; j < a.size(); ++j)
			if (a[j] <= g)
				ans = max(ans, st + 3*(j+1) + 2*min({emp, g-a[j]}));
			else break;
		if (a.size() && g+1 == a[0])
			ans = max(ans, st+1);
		trace(ans);

	}
 	return 0;
}

