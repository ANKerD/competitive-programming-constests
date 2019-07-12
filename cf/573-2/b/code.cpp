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

int ans = 2;

void inline solve(int a[]) {
	// for (int i = 0; i < 10; ++i)
	// 	cout << a[i] << ' ';
	// cout << '\n';
	for (int i = 0; i < 10; ++i)
		ans = min(ans, 3-a[i]);
	int b[10];
	for (int i = 0; i < 10; ++i)
		if (a[i]) b[i] = 1;
		else b[i] = 0;
	for (int i = 0; i < 8; ++i)
		ans = min(ans, 3-(b[i]+b[i+1]+b[i+2]));
}

int main(){
	char c;
	int a;
	int m[10], s[10], p[10];
	memset(p,0,sizeof p);
	memset(m,0,sizeof m);
	memset(s,0,sizeof s);
	for (int i = 0; i < 3; ++i) {
		string x;
		cin >> x;
		c = x[1];
		a = x[0]-'0';
		if (c == 'm') m[a]++;
		if (c == 'p') p[a]++;
		if (c == 's') s[a]++;
		// trace(a, s[a], m[a], p[a]);
	}
	
	solve(s);
	solve(m);
	solve(p);
	
	cout << ans << '\n';
 	return 0;
}

