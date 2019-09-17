#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 2001

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn][maxn];
int dig[2*maxn][2];
int n;

inline int get(int i, int j, bool ismain = true) {
	return ismain ? n-i+j : 2*n -i -j +1;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int &x = a[i][j];
			cin >> x;
			dig[get(i,j,1)][1] += x;
			dig[get(i,j,0)][0] += x;
		}
	int x1,x2,y1,y2;
	x1=x2=y1=1;
	y2 = 2;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			if ((i+j)&1) {
				if (dig[get(i ,j ,1)][1] + dig[get(i ,j ,0)][0] - a[i][j] > 
					dig[get(x1,y1,1)][1] + dig[get(x1,y1,0)][0] - a[x1][y1])
					x1=i,y1=j;
			} else {
				if (dig[get(i ,j ,1)][1] + dig[get(i ,j ,0)][0] - a[i][j] > dig[get(x2,y2,1)][1] + dig[get(x2,y2,0)][0] - a[x2][y2])
					x2=i,y2=j;
			}
	trace(dig[get(x2,y2,1)][1] + dig[get(x2,y2,0)][0] + dig[get(x1,y1,1)][1] + dig[get(x1,y1,0)][0] - a[x1][y1] - a[x2][y2]);
	trace(x1,y1,x2,y2);
 	return 0;
}