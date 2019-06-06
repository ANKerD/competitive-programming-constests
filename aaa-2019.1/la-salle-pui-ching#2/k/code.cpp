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

int a[maxn][maxn];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n,m,k;
void go(int x, int y){
	for(int z = 0; z < 4; z++){
		// trace(z);
		for (int i = x+dx[z], j = y+dy[z]; ;i += dx[z], j += dy[z]){
			// trace(x,i,y,j);
			if(i < 1 || j < 1 || i > n || j > m)
				break;
			if(a[i][j]){
				for (int q = x+dx[z], w = y+dy[z]; 
					q <=i && w <=j ;
					q += dx[z], w += dy[z])
					a[q][w] = 1;
				return;
			}
		}
			
	}
}

int main(){
	cin >> n >> m >> k;
	memset(a,0, sizeof a);
	int x, y;
	// trace(n,m,k);
	for(int z = 0; z < k; z++){
		cin >> x >> y;
		a[x][y] = 1;
		// trace(x,y);
		// go(x,y);
	}

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++)
	// 		cout << a[i][j];
	// 	cout << '\n';
	// }

	set<ii> ans;
	if(!a[1][1]) ans.insert(mp(1,1));
	if(!a[n][1]) ans.insert(mp(n,1));
	if(!a[1][m]) ans.insert(mp(1,m));
	if(!a[n][m]) ans.insert(mp(n,m));
	cout << (int) ans.size() << '\n';

 	return 0;
}


