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
#define maxn 1010
#define INF 1000000000

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n,m;
char c[maxn][maxn];
int vis[maxn][maxn];

int dfs(int i, int j, int &sz){
	if (i < 1 || j < 1 || i > n || j > m)
		return 0;
	
	// if (vis[i][j] == -1) return -1;
	if (vis[i][j]) return vis[i][j];
	int x=i, y=j;
	switch (c[i][j]) {
		case 'W':
			y--;
			break;
		case 'E':
			y++;
			break;
		case 'N':
			x--;
			break;
		case 'S':
			x++;
			break;
	}
	vis[i][j] = -1;
	// int z = dfs(x,y,sz);
	if (vis[x][y] > 0){

		vis[i][j] = 1+vis[x][y];
	} else {

		sz++;
		dfs(x,y,sz);
		vis[i][j] = sz;
	}
		
	// 	return -1;
	// } else {

	// 	vis[i][j] += z+1;
	// }

	return vis[i][j];
}

int main(){

	// int x = 1, y = 1;
	cin >> n >> m;
	// char c;
	ll ans = 0;
	// trace(n,m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];

	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if(!vis[i][j]){

				int sz = 0;

				int x = dfs(i,j,sz);
			}
			// break;
			// if (x == -1)
			// 	ans += sz;
			// else
			// 	ans += x;
		}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			// ans += vis[i][j];
			cout << vis[i][j] << ' ';
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += vis[i][j];

	cout << ans << '\n';

 	return 0;
}

