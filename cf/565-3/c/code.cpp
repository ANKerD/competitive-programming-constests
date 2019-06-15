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
#define maxn 500010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}


int n, a[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int f[100];
	memset(f,0, sizeof f);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	// 4,8,15,16,23,42

	int ans = 0;
	for (int i = n-1; i+1; --i) {
		if (a[i] == 42)
			++f[42];
		if (a[i] == 23)
			f[23] = min(f[23]+1, f[42]);
		if (a[i] == 16)
			f[16] = min(f[16]+1, f[23]);
		if (a[i] == 15)
			f[15] = min(f[15]+1, f[16]);
		if (a[i] == 8)
			f[8] = min(f[8]+1, f[15]);
		if (a[i] == 4) {
			f[4] = min(f[4]+1, f[8]);
			ans = f[4];
		}
		
	}

	cout << n - 6*ans << '\n';
 	return 0;
}

