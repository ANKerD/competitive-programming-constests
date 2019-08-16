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

int a[5][5];

void dfs(int i, int j) {
	if (i < 0 || i >= 5 || j < 0 || j >= 5 || a[i][j]) return;
	a[i][j] = 2;
	dfs(i+1,j+0);
	dfs(i+0,j+1);
	dfs(i-1,j+0);
	dfs(i+0,j-1);
}

int main(){
	int n;
	cin >> n;
	while (n--) {
		
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				cin >> a[i][j];
		dfs(4,4);
		if (a[0][0] == 2) trace("COPS");
		else trace("ROBBERS");
	}
 	return 0;
}


