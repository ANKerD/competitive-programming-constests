#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
// #define int long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vint vector<int>
#define maxn 1010
#define INF 1e9

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn][maxn];
int m[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
int n;
void pr(int arr[maxn][maxn]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-i; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void fuintfiint(int arr[maxn][maxn]){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = -INF;
}

int main(){
	while(1){
		cin >> n;
		if(!n) break;
		fuintfiint(a);
		fuintfiint(b);
		fuintfiint(c);
		fuintfiint(m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= i; j++)
				cin >> b[i-j][j];
		
		for(int i = 0; i < n; i++){
			c[i][0] = b[i][0];
			for(int j = 1; j < n-i; j++)
				c[i][j] = b[i][j] + c[i][j-1];
		}

		int ans = -INF;
		a[0][n] = ans;
		for(int i = n-1; i+1; i--){
			ans = max(ans, a[0][i] = c[0][i]);
			m[0][i] = max(ans, a[0][i+1]);
		}

		for(int i = 1; i < n; i++){
			m[i][n-1] = a[i][n-1] = c[i][n-1] + m[i-1][n-1];
			for(int j = n-i-1; j+1; j--){
				a[i][j] = c[i][j] + m[i-1][j];
				ans = max(ans, a[i][j]);
				m[i][j] = max(a[i][j], m[i][j+1]);
			}
		}

		cout << max(0, ans) << '\n';
	}
 	return 0;
}

