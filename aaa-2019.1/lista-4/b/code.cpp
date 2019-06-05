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
#define maxn 4010
#define maxk 810
#define INF 1000000000

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n, k, m[maxn][maxn];
int s[maxn][maxn];
int dp[maxk][maxn];

void solve(int sz, int l, int r, int st, int nd){
	if(l>r) return;

	int mid = (l+r)/2;
	int top;
	
	for(int dt = st; dt <= nd; ++dt){
		int tmp = dp[sz-1][dt-1] + s[dt][mid];
		
		if(tmp < dp[sz][mid]){
			
			dp[sz][mid] = tmp;
			top = dt;
		}
	}

	solve(sz, l, mid-1, st, top);
	solve(sz, mid+1, r, top, nd);
}

inline void fastscan(int &x) {
	register int c;
	x=0;
	c=getchar_unlocked();
	for(;(c>47 && c<58);c=getchar_unlocked())
		x = (x<<1) + (x<<3) +c -48;
}

int main(){
	fastscan(n);
	fastscan(k);
	for(register int i = 1; i <= n; ++i)	
		for(register int j = 1; j <= n; ++j)	
			fastscan(m[i][j]);

	for(register int i = 1; i < n; ++i){
		s[i][i] = 0;
		for(register int j = 1; j+i <= n; ++j){
			int l = i+j;
			s[j][l] = m[j][l] + s[j][l-1] + s[j+1][l] - s[j+1][l-1];
		}
	}

	for(register int i = 0; i < maxk; ++i)	
		for(register int j = 0; j < maxn; ++j)	
			dp[i][j] = INF;
	
	dp[0][0] = 0;
	for(register int i = 1; i <= k; ++i){
		solve(i, 1, n, 1, n);
	}
	
	printf("%d\n", dp[k][n]);
 	return 0;
}

