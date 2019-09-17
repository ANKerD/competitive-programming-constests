#include <bits/stdc++.h>
using namespace std;

int a,b,c,n;

int main(){
	cin >> n >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i*a <= n; ++i)
		for (int j = 0; i*a+j*b <= n; ++j)
			if ((n-i*a-j*b) % c == 0)
				ans = max(ans, i + j + (n-i*a-j*b) / c);
	cout << ans << '\n';
 	return 0;
}

