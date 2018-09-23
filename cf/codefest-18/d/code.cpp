#include <bits/stdc++.h>
#define MAXN 200010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1]);

#define swap(a, b) auto temp = a; a = b; b = temp;
#define mp makepair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<ll> vll;
typedef vector<double> vd;

vi g[MAXN];
// vi path;
int level[MAXN];
int parent[MAXN];

void dfs(int v, int p){
	// trace2(v,p);
	level[v] = 1+level[p];
	parent[v] = p;
	// path.pb(v);
	for(auto u: g[v])
		if(u != p)
			dfs(u, v);
}

int main(){
	int n, a,b;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	vi target;
	for(int i = 0; i < n; i++){
		cin >> a;
		target.pb(a);
	}
	level[1]=0;
	parent[1] = 1;
	dfs(1, 1);
	for(int p = 0, ch=1; p < n; p++){
		// if(p+1<n){
		// 	if(level[p+1]-level[p] > 1){
		// 		trace1("No");
		// 		return 0;
		// 	}
		// }
		for(int j = 0; j < g[target[p]].size()-(p==0?0:1); j++){
			if(parent[target[ch]] != target[p]){
				trace1("No");
				return 0;
			}
			ch++;
		}
	}
	trace1("Yes");

 	return 0;
}
