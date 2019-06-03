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

 	
	int n;
	cin >> n;
		// trace("lkuuy");
	char m[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> m[i][j];

	bool ok = 1;
	for(int i = 1; i+1 < n; i++)
		for(int j = 1; j+1 < n; j++){

			if(m[i][j] == '.' && 
				m[i-1][j] == '.' && 
				m[i+1][j] == '.' && 
				m[i][j-1] == '.' && 
				m[i][j+1] == '.'){
					m[i][j] = '#';
					m[i-1][j] = '#';
					m[i+1][j] = '#';
					m[i][j-1] = '#';
					m[i][j+1] = '#';
				}
		}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(m[i][j] == '.')
				ok = 0;
	if(ok) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}

