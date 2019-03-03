#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define int long long
typedef vector<int> vi;

int a[maxn];
int f[maxn];

int32_t main(){
	int n;
	cin >> n;
	
	memset(f,0,sizeof f);
	
	vector<int> nm;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);

	set<int> t;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			t.insert(a[i]+a[j]);

	int ans = 1;
	for(auto it = t.begin(); it != t.end(); it++){
		int l = 0;
		int target = *it;
		int i = 0, j = n-1; 
		while(i < j){
			if(a[i]+a[j] == target){
				l++,
				i++,
				j--;
			} else if(a[i]+a[j] > target){
				j--;
			} else {
				i++;
			}
		}
		ans = max(ans, l);
	}
	printf("%lld\n", min(ans, n/2));


 	return 0;
}
