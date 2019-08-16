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
	int n,m,x,y;
	while (1) {
		cin >> n >> m;
		if (n+m == 0) break;
		char a[n][m];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)	
				cin >> a[i][j];
		cin >> x >> y;
		// trace(n,m);
		for (int i = 0; i < n; ++i)
			for (int k = 0; k < x/n; ++k) {
				for (int j = 0; j < m; ++j)	
					for (int l = 0; l < y/m; ++l) {
						// trace("yo");
						cout << a[i][j];
					}
				cout << '\n';
			}
		cout << '\n';
	}
 	return 0;
}

