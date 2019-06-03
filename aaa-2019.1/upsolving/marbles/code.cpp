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
#define maxn 101

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int m[maxn][maxn];
void dgb(int i, int j, int k, int t, int m){
	// if(i == 1 && j == 2)
	// 	trace(i, j, k, t, m);
}

int main(){
	// for(int i = 0; i < maxn; i++){
	// 	m[i][0] = m[0][i] = i;
	// }
	set<int> a;
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			if(j == i || !i || !j){
				m[i][j] = 999;
				continue;
			}
			a.clear();
			for(int k = 0; k < j; k++)	
				a.insert(m[i][k]), dgb(i,j,k,-1,m[i][k]);
			for(int k = 0; k < i; k++)	
				a.insert(m[k][j]), dgb(i,j,k,-2,m[i][k]);
			for(int k = min(i,j); k; --k)	
				a.insert(m[i-k][j-k]), dgb(i,j,k,-3,m[i][k]);
			// if(i==1 && j == 2){
			// 	for (auto it = a.begin(); it!=a.end(); ++it)
			// 		cout << *it << ' ';
			// 	cout << '\n';
			// }
			for(int k = 0; k < 311; k++){
				// if(i==1 && j == 2){
				// 	trace(!a.count(k), k);
				// }	
				m[i][j] = k;
				if(!a.count(k))
					break;
			}
		}
		// if(i<10){
		// 	for(int j = 0; j < 10; j++)
		// 		cout << m[i][j] << '\t';
		// 	cout << '\n';
		// }
	}
	int n,x,y;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		if(x == y){
			cout << "Y\n";
			return 0;
		}
		// x--;y--;
		ans ^= m[x][y];
	}

	int sz = 5;
	// for(int i = 0; i < sz; i++){
	// 	for(int j = 0; j < sz; j++)
	// 		cout << m[i][j] << '\t';
	// 	cout << '\n';
	// }
		// trace(ans);
	if(ans) cout << "Y\n";
	else cout << "N\n";
 	// return 0;
}

