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
#define maxn 200010
// #define int long long

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int va[maxn], vb[maxn];
int n,m,ta,tb,k;

int get(int i) {
	auto it = lower_bound(vb, vb+m, va[i]+ta);
	int bpos = vb+m-it;
	bpos = m-bpos;
	// if (bpos == 0)	
	// 	return -1;
	// trace(bpos,k-i, m-1);
	if (bpos+k-i >= m)
		return -1;
	return vb[bpos+k-i]+tb;
}

int32_t main(){
	// cout << 1000000000 << "n\n";
	cin >> n>>m>>ta>>tb>>k;

	for (int i = 0; i < n; ++i)
		cin >> va[i];
	sort(va,va+n);
	for (int i = 0; i < m; ++i)
		cin >> vb[i];
	sort(vb,vb+m);

	if (k >= min(n,m)){
		cout << "-1\n";
		return 0;
	}
	int ans = -1;
	for (int i = 0; i <= k; ++i){
		int now = get(i);
		if (now != -1)
			ans = max(ans, now);
	}

	cout << ans << "\n";

 	return 0;
}

