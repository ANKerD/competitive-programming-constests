#include <bits/stdc++.h>
using namespace std;
#define maxn 1010

int n, m, a[maxn];
int dp[maxn][maxn];
int op[maxn][maxn];

int main(){
	while(cin >> n >> m){
		a[0] = 0;
		a[m+1] = n;
		for(int i = 1; i <= m; i++)
			cin >> a[i];
		
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= m+1; i++)
			for(int j = 0; i+j <= m+1; j++){
				if(i == 1){
					dp[j][j+i] = 0;
					continue;
				}

				int ans = 1e9;
				
				int bg,nd;
				if(i == 2)	
					bg = j+1, nd = i+j;
				else 
					bg = op[j][i+j-1], nd = op[j+1][i+j];
				
				for(int k = bg; k <= nd; k++){
					int v = dp[j][k]+dp[k][j+i];
					if(ans > v){
						ans = v;
						op[j][j+i] = k;
					}
				}
				dp[j][j+i] = ans + a[j+i] - a[j];
			}
		cout << dp[0][m+1] << '\n';
	}
 	return 0;
}
