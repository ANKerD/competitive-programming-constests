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
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int f[maxn];
int g[maxn];
int main(){
	int n;
	cin >> n;
	set<int> a;
	int x;
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	int ans = 1;

	int last = maxn-1;

	f[0] = g[0] = 1;

	
	for(int i = 0; i < n; i++){
		cin >> x;
		if(!a.count(x))
			a.insert(x), g[0]++;
		g[f[x]]--;
		f[x]++;
		g[f[x]]++;
		
		trace(x, f[x], g[f[x]], ((int) a.size()));
		// if(g[f[last]] * ((int) a.size() - 1) == i+1)
		// 	ans = i+2;
		// last = x;
	}

	cout << ans << '\n';
 	return 0;
}

