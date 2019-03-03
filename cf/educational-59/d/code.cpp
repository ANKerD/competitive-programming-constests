#include <bits/stdc++.h>
#define maxn 5210
using namespace std;

bool m[maxn][maxn];

int main(){
	int n;
	// scanf(" %d", &n);
	// char c;
	cin >> n;
	// vector<string> v;
	string a;
	for(register int j = 0; j < n; j++){
		cin >> a;
		for(int i = 0; i < (n>>2); i++)
			for(int k = 0; k < 4; k++)
				m[j][(i<<2)+k] = a[i]&((1<<(k))-1);
	}
	for(int i = 0; i < n; i++){
		for(register int j = 0; j < n; j++)
			cout << m[i][j];
		cout << "\n";
	}
			
	int x = 1, old = 1;
	while(x <= n){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(m[i][j] != m[i/x][j/x]){
					cout << old << "\n";
					return 0;
				}
			}
		old = x;
		x++;
		while(x < n && n%x)x++;
	}
	cout << old << "\n";
	return 0;
}
