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
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	int a[m];
	for(int i = 0; i < m; i++)
		cin >> a[i];
	int f,mx = ((1<<n)-1);
	cin >> f;
	int ans = 0;
	for(int i = 0; i < m; i++){
		int d = __builtin_popcount(a[i]^f&mx);
		if(d <= k) ans++;
	}
	trace(ans);

 	return 0;
}

