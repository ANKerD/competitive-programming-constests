#include <bits/stdc++.h>
#define maxn 3010
#define int long long
using namespace std;

int dp[maxn];

int a,b,c,d;

int32_t main(){
	cin >> a >> b >> c >> d;
	int ans = 0;
	for(int i = 0; i*a <= d; i++)
		for(int j = 0; j*b <= d+a*i; j++){
			int x = d - i*a- j*b;
			if(x >= 0 && x % c == 0)
				ans++;
		}

	cout << ans << '\n';
	return 0;
}