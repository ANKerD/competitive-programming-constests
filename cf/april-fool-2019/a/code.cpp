#include <bits/stdc++.h>
using namespace std;

int a[16], n;
int solve(int l, int r){
	if(is_sorted(a+l,a+r+1))
		return r-l+1;
	int mid = (l+r)/2;
	int ans = max(
		solve(l, mid),
		solve(mid+1, r)
	);
	return ans;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int sz = solve(0,n-1);
	printf("%d\n", sz);

 	return 0;
}
