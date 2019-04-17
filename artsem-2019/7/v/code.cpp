#include <bits/stdc++.h>
#define ii pair<int, int>
#define maxn 100010
#define fi first
#define se second
using namespace std;

vector<ii> g[maxn];
set<int> vt[3];
int color[maxn];

bool bicolor(int v, int c){
	if(color[v]) return color[v] == c;
	
	color[v] = c;
	for(auto j: g[v]){
		vt[c].insert(j.fi);
		if(!bicolor(j.fi, 3-c))
			return false;
	}
	return true;
}

int main(){
	int n,m,x,y,r;
	cin >> n >> m;
	memset(color, 0, sizeof color);
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		r = x;
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
	}

	bool ok = true;
	for(int i = 1; i <= n; i++)
		if(!color[i])
			ok = ok && bicolor(i, 1);
			
	if(!ok)
		cout << "-1\n";
	else {
		cout << (int) vt[1].size() << '\n';
		for(auto i = vt[1].begin(); i != vt[1].end(); i++)
			cout << *i << " ";
		cout << '\n';
		cout << (int) vt[2].size() << '\n';
		for(auto i = vt[2].begin(); i != vt[2].end(); i++)
			cout << *i << " ";
	}
 	return 0;
}
