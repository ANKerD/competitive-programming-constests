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
	int t;
	cin >> t;
	while(t--) {
		int a[10][10];
		memset(a,-1,sizeof a);
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j <= i; j++)
				cin >> a[i*2][j*2];
		for (int i = 8; i>=0; --i) {
			for (int j = 1; j <= i; j+=2)
				a[i][j] = (a[i-2][j-1]-a[i][j+1]-a[i][j-1])/2;
			--i;
			for (int j = 0; j <= i; j++)
				a[i][j] = a[i+1][j]+a[i+1][j+1];
			// break;
		}
		for (int i = 0; i < 9; ++i) {
			int ou = false;
			for (int j = 0; j <= i; j+=1) {
				if (ou) cout << ' '; ou=1;
				cout << a[i][j];
			}
			cout << '\n';
		}
		// return 0;
	}
 	return 0;
}

