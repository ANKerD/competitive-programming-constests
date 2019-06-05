#include <bits/stdc++.h>
using namespace std;
#define maxn 1010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char a[maxn][maxn];

int main(){
	int n,m,o,buy=1;
	while(1){
		cin >> n >> m >> o;
		if(n+m+o == 0) break;
		// trace(n,m,o);
		int ii, jj, z;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; ++j)	{
				cin >> a[i][j];
				if(a[i][j] == 'N'){
					ii=i;
					jj=j;
					z = 0;
				}
				if(a[i][j] == 'L'){
					ii=i;
					jj=j;
					z = 1;
				}
				if(a[i][j] == 'S'){
					ii=i;
					jj=j;
					z = 2;
				}
				if(a[i][j] == 'O'){
					ii=i;
					jj=j;
					z = 3;
				}
				// cout << a[i][j];
			}
			// cout << '\n';
		}

		string s;
		cin >> s;

		int i=ii, j=jj, x,y, ans=0;

		// trace(ii, jj, z);

		for (int w = 0; w < o; w++){
			if (s[w] == 'E'){
				z = (z-1+4)%4;
				continue;
			} 
			if (s[w] == 'D'){
				z = (z+1+4)%4;
				continue;
			}
			x = i+dx[z];
			y = j+dy[z];
			// trace(i,j,x,y, z);
			if(x < 1 || y < 1 || x > n || y > m || a[x][y] == '#')
				continue;
			i = x;
			j = y;
			if (a[i][j] == '*'){
				a[i][j] = '.';
				// trace('*', i, j);
				ans++;
			}
		}
		cout << ans << '\n';
		
		// if(!buy--) break;
	}
 	return 0;
}

