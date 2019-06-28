#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
int a[maxn];
int b[maxn];

int main(){
	int n,k;
	cin >> n >> k;
	b[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i] + b[i-1];
	}
	int ans = 1e9;
	int id = 0;
	for (int i = k; i <= n; ++i) {
		// printf("%d %d\n", i-k+1, b[i]-b[i-k]);
		if (b[i]-b[i-k] < ans)
			ans = b[i]-b[i-k], id = i-k+1;
	}
	cout << id << '\n';

 	return 0;
}

