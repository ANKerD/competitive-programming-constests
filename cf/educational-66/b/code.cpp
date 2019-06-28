#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll mx = 4294967295LL;
ll cont;
bool fuder = 0;

ll dfs(ll val=1, ll over=0) {
	string s;
	ll x;
	ll cur = 0;
	
	while(cont) {
		cont--;
		cin >> s;
		if (s == "add") {
			if (over) {
				fuder = 1;
			}
			
			cur += val;

			if (cur >= mx)
				fuder = 1;
		} else if (s == "end") {
			return cur;
		} else {
			cin >> x;
			cur += dfs(val*x, over || val <= 0 || val >= mx || val*x <= 0 || val*x >= mx);
		}
	}
	return cur;
}

int main(){
	cin >> cont;
	ll ans = dfs();
	if (ans >= mx)
		fuder = 1;
	if (fuder)
		trace("OVERFLOW!!!");
	else
		trace(ans);

	// int x = 100000;
	// int y = x*x;
	// trace(x,y, y/x);

 	return 0;
}