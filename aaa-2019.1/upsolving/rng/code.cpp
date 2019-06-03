#include <bits/stdc++.h>
#define mod 997

using namespace std;

int gauss (vector < vector<int> > a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int main(){
	// string s;
	// cin >> s;
	// const int maxn = 1 << 8;

	// int ans[6];
	// memset(ans, -1, sizeof ans);
	// for (int i = 0; i < maxn; i++){
	// 	int tmp[5];
	// 	for (int j = 0; j < 4; j++) {
	// 		tmp[j+1] = 1 + i / (1<<(j<<1)) % 4;
	// 		// cout << tmp[j+1];
	// 	}

	// 	for (int j = 0; j < 4; j++) {
	// 		int x = j+1;
	// 		int k = 0;
	// 		while(k < 15){
	// 			if (s[k] == '?' || s[k]-'0' == x)
	// 				x = tmp[x];
	// 			else 
	// 				break;
	// 			k++;
	// 		}
	// 		if (k == 15){
	// 			// cout << i << ' ' << j+1 << '\n';
	// 			// TODO: solve gaussian elimination
	// 			// for (int j = 0; j < 4; j++) 
	// 			// 	cout << tmp[j+1];
				
	// 			return 0;
	// 		}
	// 	}
	// 	// cout << '\n';
	// }

	// for (int i = 0; i < 6; i++)
	// 	cout << ans[i] << " \n"[i==5];

 	// return 0;
}
// while(true){
// 	cin >> n >> m;
// 	if(n+m == 0) break;
// }
