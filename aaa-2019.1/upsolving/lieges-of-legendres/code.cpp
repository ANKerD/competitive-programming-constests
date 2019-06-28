#include <bits/stdc++.h>
using namespace std;

int oddarr[7] = {0,1,0,1,2,0,2};

map<int, int> dp;

int mex(int a) {
	if (a == 1) return 2;
	else return 1;
}

int getodd(int v) {
	if (v <= 6) return oddarr[v];
	if (dp.count(v)) return dp[v];
	if (v&1) return 0;
	return dp[v] = mex(getodd(v>>1));
}

int geteven(int v) {
	if (v == 2) return 2;
	if (v < 2) return v&1;
	return (++v)&1;
}

int main(){
	// for (int i = 0; i < 15; i++)
	// 	printf("%d %d\n", i, getodd(i));
	// return 0;
	int n,x,k,ans=0;
	cin >> n >> k;
	k = k&1;
	while (n--) {
		cin >> x;
		if (k)
			ans ^= getodd(x);
		else
			ans ^= geteven(x);
	}
	if (ans)
		cout << "Kevin\n";
	else	
		cout << "Nicky\n";
 	return 0;
}


