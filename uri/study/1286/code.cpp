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

int d[40][40];
int n,t,c[40], v[40];

int solve(int i, int l){
	if(i == n) return 0;
	if(d[i][l] != -1) return d[i][l];

	int ans = solve(i+1, l);
	
	if(v[i] <= l) 
		ans = max(ans, c[i] + solve(i+1, l-v[i]));
	return d[i][l] = ans;
}

int main(){
	while(cin >> n){
		if(!n) break;
		cin >> t;
		memset(d, -1, sizeof d);
		for(int i = 0; i < n; i++)
			cin >> c[i] >> v[i];
		cout << solve(0, t) << " min.\n";
	}

 	return 0;
}

