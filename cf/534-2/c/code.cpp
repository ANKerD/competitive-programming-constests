#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2000000
#define mod 1000000007
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

bool g[4][4];
string a;

void pr(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
			cout << g[i][j];
		cout << '\n';
	}
	cout << '\n';
}

int main(){
	cin >> a;
	// trace1(a);
	memset(g,0,sizeof g);
	for(int k = 0; k < (int) a.size(); k++){
		char op = a[k];
		int x=-1, y=-1;
		for(int i = 0; i < 4 && x == -1; i++)
			for(int j = 0; j < 4; j++){
				if(g[i][j]) continue;
				if(op=='0'){
					if(i<3 && !g[i+1][j])
						x = i+1,y = j;
				} else {
					if(j<3 && !g[i][j+1])
						x = i,y = j+1;
				}
					
				if(x != -1){
					g[x][y] = g[i][j] = 1;
					trace2(i+1,j+1);
					break;
				}
			}
			
		int row = -1;
		for(int i = 0; i < 4; i++){
			bool ok = 1;
			for(int j = 0; j < 4; j++)
				if(!g[i][j])
					ok = 0;
			if(ok){
				row = i;
				break; 
			}
		}
		int col = -1;
		for(int j = 0; j < 4; j++){
			bool ok = 1;
			for(int i = 0; i < 4; i++)
				if(!g[i][j])
					ok = 0;
			if(ok){
				col = j;
				break; 
			}
		}
		if(row != -1)
			for(int j = 0; j < 4; j++)
				g[row][j] = 0;
		if(col != -1)
			for(int i = 0; i < 4; i++)
				g[i][col] = 0;
		pr();
	}

 	return 0;
}
