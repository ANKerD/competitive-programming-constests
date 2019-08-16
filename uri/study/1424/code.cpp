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
#define maxn 1000100

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vi a[maxn];

int main(){
	int n,q,x,y;
	while (cin >> n >> q) {

		// trace("n",n,q);
		for (int i = 0; i < n; ++i) {
			cin >> x;
			a[x].push_back(i+1);
		}
		while(q--) {
			cin >> x >> y;
			// trace(y, x, a[y].size());
			if (a[y].size() < x)
				trace(0);
			else
				trace(a[y][x-1]);
		}
		for (int i = 0; i < maxn; ++i) a[i].clear();
	}
 	return 0;
}

