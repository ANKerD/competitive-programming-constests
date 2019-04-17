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

int main(){
	int n,m,h;
	int sz[maxn][maxn];
	int INF = 1e4;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sz[i][j] = INF;
	cin >> n >> m >> h;
	for(int i = 0; i < m; i++){
		int col;
		cin >> col;
		for(int j = 0; j < n; j++)
			sz[j][i] = col;
	}

	for(int i = 0; i < n; i++){
		int col;
		cin >> col;
		for(int j = 0; j < m; j++)
			sz[i][j] = min(sz[i][j], col);
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			int active;
			cin >> active;
			if(active)
				cout << sz[i][j] << " \n"[j == m-1];
			else
				cout << 0 << " \n"[j == m-1];
		}
	
 	return 0;
}

