#include <bits/stdc++.h>
using namespace std;
#define maxn 1010
int p[2*maxn];
int find(int x) {	
	// cout << "find " << x << '\n';
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void join(int x, int y) {
	// printf("join %d %d\n",x,y);
	x = find(x);
	y = find(y);
	if (x != y)
		p[y] = x;
}

int main(){
	int n,m,ak = 0,k;
	cin >> n >> m;
	set<int> used, ans;
	for (int i = 0; i <= m; ++i)
		p[i] = i;
	// cout <<n << m;
	for (int i = 0; i < n; ++i)	{
		cin >> k;
		if (k) {
			int x,y;
			cin >> x;
			used.insert(x);
			// printf("i: %d, x=%d\n", i, x);
			// return 0;
			for (int j = 1; j < k; ++j) {
				cin >> y;
				join(x,y);
				used.insert(y);
			}
		} else ak++;
	}
	
	int res;
	if (ak == n) 
		res = n;
	else {
		for (auto u: used) 
			ans.insert(find(u));
		res = ans.size()+ak-1;
	}
	printf("%d\n", res);
}

