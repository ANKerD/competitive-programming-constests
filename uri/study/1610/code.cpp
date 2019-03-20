#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

int vis[maxn];
vector<int> g[maxn];

bool dfs(int v){
	if(vis[v]) return vis[v] == 1;
	vis[v] = 1;
	for(auto u: g[v])
		if(dfs(u))
			return true;
	vis[v] = 2;
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,x,y;
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			g[x].push_back(y);
		}
		bool merda = 0;
		for(int i = 1; i <= n && !merda; i++)
			if(!vis[i])
				merda = merda || dfs(i);

		if(merda)	
			cout << "SIM\n";
		else
			cout << "NAO\n";

		for(int i = 1; i <= n; i++)
			vis[i] = 0, g[i].clear();
	}
}