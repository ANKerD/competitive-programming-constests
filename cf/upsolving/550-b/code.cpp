#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define INF 1e9

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n,l,r,x;
int a[16];

int main(){
	cin >> n >> l >> r >> x;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a,a+n);
	int ans = 0;
	
	for(int i = 0; i < (1<<n); i++){
		if(__builtin_popcount(i) < 2) continue;
		// trace("errrror");
		int mi = INF, ma = -INF, p = 0;
		for(int j = 0; j < n; j++){
			if(i & (1<<j)){
				mi = min(mi, a[j]);
				ma = max(ma, a[j]);
				p += a[j];
			}
		}
		// trace(ma-mi, mi, ma);
		if(ma-mi >= x && p >= l && p <= r)
			ans++;
	}
		
	cout << ans << '\n';
 	return 0;
}

