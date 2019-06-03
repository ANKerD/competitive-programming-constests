#include <bits/stdc++.h>
using namespace std;

int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
int d[maxn][maxn];
int n, m;

bool ok(int z[maxn][maxn]){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m-1; j++)
			if (z[i][j] >= z[i][j+1])
				return false;
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n-1; i++)
			if (z[i][j] >= z[i+1][j])
				return false;
	return true;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			c[i][j] = min(a[i][j], b[i][j]), d[i][j] = max(a[i][j], b[i][j]);

	if (ok(c) && ok(d))
		cout << "Possible\n";
	else
		cout << "Impossible\n";
 	return 0;
}

